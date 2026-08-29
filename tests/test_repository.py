from __future__ import annotations

import json
import importlib.util
import pathlib
import re
import unittest
from unittest import mock


ROOT = pathlib.Path(__file__).resolve().parents[1]


class RepositoryTests(unittest.TestCase):
    def test_release_metadata(self) -> None:
        project = json.loads((ROOT / "project.json").read_text())
        self.assertEqual(project["version"], "3.0.0")
        self.assertEqual(project["openwrt_release_version"], "1.16.0-rc7")
        self.assertTrue(project["runtime_configuration_persistent"])
        self.assertTrue(project["sysupgrade_supported"])
        self.assertTrue(project["wifi_supported"])

    def test_qualified_source_lock(self) -> None:
        lock = json.loads((ROOT / "openwrt/source-lock.json").read_text())
        self.assertEqual(lock["release_version"], "1.16.0-rc7")
        self.assertEqual(lock["openwrt"]["commit"], "f0a60eee2fe051741c643ea6118718aae1ef17fb")
        self.assertEqual(set(lock["feeds"]), {"luci", "packages", "routing", "telephony", "video"})
        for feed in lock["feeds"].values():
            self.assertRegex(feed["commit"], r"^[0-9a-f]{40}$")

    def test_current_document_links(self) -> None:
        documents = [ROOT / "README.md", ROOT / "STATUS.md", ROOT / "prebuilt/README.md"]
        documents.extend(path for path in (ROOT / "docs").rglob("*.md") if "history" not in path.parts)
        documents.extend((ROOT / "openwrt/docs").glob("*.md"))
        documents.extend([ROOT / "openwrt/README.md", ROOT / "openwrt/history/README.md"])
        pattern = re.compile(r"\[[^]]+\]\(([^)]+)\)")
        missing: list[str] = []
        for document in documents:
            for target in pattern.findall(document.read_text(errors="replace")):
                if target.startswith(("http://", "https://", "mailto:", "#")):
                    continue
                path = target.split("#", 1)[0]
                if path and not (document.parent / path).resolve().exists():
                    missing.append(f"{document.relative_to(ROOT)} -> {target}")
        self.assertEqual(missing, [])

    def test_liveboot_prebuilt_prompt_can_be_declined(self) -> None:
        path = ROOT / "openwrt/scripts/release/liveboot.py"
        spec = importlib.util.spec_from_file_location("rv220w_liveboot", path)
        assert spec and spec.loader
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        with mock.patch("builtins.input", return_value="n"), mock.patch.object(module.subprocess, "run") as run:
            selected = module.artifact_paths(False, False)
        self.assertEqual(selected, (module.ART / module.INIT_NAME, module.ART / module.SYS_NAME))
        run.assert_not_called()

    def test_liveboot_prebuilt_prompt_verifies_acceptance(self) -> None:
        path = ROOT / "openwrt/scripts/release/liveboot.py"
        spec = importlib.util.spec_from_file_location("rv220w_liveboot_accept", path)
        assert spec and spec.loader
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        with mock.patch("builtins.input", return_value=""), mock.patch.object(module.subprocess, "run") as run:
            selected = module.artifact_paths(False, False)
        self.assertEqual(selected, (module.PREBUILT / module.INIT_NAME, module.PREBUILT / module.SYS_NAME))
        run.assert_called_once_with(["make", "prebuilt-check"], cwd=module.ROOT, check=True)


if __name__ == "__main__":
    unittest.main()

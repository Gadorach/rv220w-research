# Setup failure: recreate appears hung (v1.0.2)

## Symptom

`./rv220w.fish setup-box --recreate` printed only the recreate warning and then
remained idle indefinitely.

## Root cause

The v1.0.2 script ran `distrobox stop NAME` without Distrobox's non-interactive
`--yes` option and redirected the command's output. Distrobox was waiting for a
confirmation response, but the prompt was invisible. No Ubuntu image was being
pulled and no container was being rebuilt during that wait.

## Correction

v1.0.3 bypasses the interactive Distrobox stop/remove sequence for this narrow
recovery operation and invokes:

```text
timeout --foreground 30s podman rm --force --time 3 --ignore NAME
```

The named container may have been created by Distrobox or Toolbx. The operation
is explicit, bounded, and leaves the shared host home/workspace untouched.

## Recovery

Apply the v1.0.3 overlay, then run:

```fish
./rv220w.fish doctor
./rv220w.fish setup-box --recreate
./rv220w.fish doctor
./rv220w.fish prepare-sources
```

For cleanup only:

```fish
./rv220w.fish setup-box --remove-only
```

The first Ubuntu image pull and package installation may legitimately take a few
minutes, but those phases display Podman/Distrobox or apt progress. Only the old
container removal is hard-bounded to 30 seconds.

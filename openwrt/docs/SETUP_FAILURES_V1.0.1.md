# Setup failures corrected in v1.0.1

## `string join: -S: unknown option`

The v1.0.0 host setup printed a pacman command with:

```fish
string join ' ' $cmd
```

Because the command list contained `-S`, Fish treated it as an option to
`string join`. The corrected form is:

```fish
string join ' ' -- $cmd
```

The same separator is used anywhere a list of shell arguments is joined.

## Pacman attempted to upgrade installed packages

The old script called `pacman -S --needed` with its complete dependency list.
`--needed` skips a package only when the installed version already matches the
selected repository version. If the sync database advertises a newer version,
pacman can select an upgrade even though the command already exists.

The v1.0.1 script first runs:

```fish
pacman -T $packages
```

and sends only missing packages to pacman. A host where `doctor` reports every
required command as available therefore becomes a no-op.

Repeated package 404 errors generally indicate that the local sync database and
selected mirrors are temporarily out of step. The toolkit does not hide or
force past that condition. Update CachyOS normally, or intentionally run:

```fish
./rv220w.fish setup-host --sync-upgrade
```

## `Expected a string, but found a redirection`

Fish does not implement Bash heredoc syntax:

```text
cat > file <<'BASH'
```

v1.0.0 embedded several Bash programs that way, causing Fish to reject the
scripts before execution. v1.0.1 stores those programs directly in:

```text
scripts/inner/
├── provision-openwrt-box.sh
├── prepare-sources.sh
├── build-openwrt.sh
└── build-linux-reference.sh
```

The Fish wrappers now invoke those files through Distrobox.

## Validation

After applying the update:

```fish
./rv220w.fish doctor
./rv220w.fish setup-host
./rv220w.fish setup-box
./rv220w.fish prepare-sources
```

`doctor` should report Fish and Bash syntax checks before any container work is
started.

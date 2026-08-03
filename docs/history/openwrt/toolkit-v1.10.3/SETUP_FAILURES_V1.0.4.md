# v1.0.4 Ubuntu Universe / MIPS64 cross-compiler recovery

## Observed failure

Ubuntu 24.04 Distrobox creation succeeded and the normal OpenWrt build packages
started installing, but provisioning stopped at:

```text
The following packages have unmet dependencies:
 gcc-mips64-linux-gnuabi64 : Depends: gcc-12-mips64-linux-gnuabi64 ...
                             but it is not installable
```

## Cause

The MIPS64 cross-compiler packages used by the standalone upstream-Linux
reference build are published in Ubuntu's **Universe** component. A minimal
Ubuntu OCI image may not have that component enabled. The v1.0.3 provisioner
also treated this optional external compiler as mandatory for every workflow,
even though OpenWrt builds and uses its own target toolchain.

## v1.0.4 behavior

The provisioner now performs four visible phases:

1. refresh package metadata;
2. install the OpenWrt build prerequisites;
3. enable Universe and attempt the optional MIPS64 reference compiler;
4. validate and clean the container.

The main environment is considered ready when the OpenWrt prerequisites and
Perl `FindBin` are present. Failure to install `mips64-linux-gnuabi64-gcc`
produces a warning and disables only `build-linux`; it does not block
`prepare-sources` or any OpenWrt build.

## Recovery

The Ubuntu box that v1.0.3 created is correct and should be reused. Do not
recreate it again:

```fish
./rv220w.fish setup-box
./rv220w.fish doctor
./rv220w.fish prepare-sources
```

A successful `doctor` reports the OpenWrt tools separately from the optional
reference compiler.

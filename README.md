# NDS CIA/3DSX Converter — v0.1

Initial Nintendo 3DS homebrew prototype.

## What this first build does
- Builds a 3DS homebrew application (`.3dsx`).
- Starts on the 3DS and displays a simple status screen.
- Creates/checks `sdmc:/converterNC3/` on the SD card.
- Uses `sdmc:/converterNC3/` as the future destination for generated forwarders.

## Important
This is only the first runnable prototype. It does **not** yet convert NDS ROMs or generate per-game CIA/3DSX forwarders.

An NDS ROM is not converted into native 3DS code. The intended approach is to create a forwarder that launches the original `.nds` using nds-bootstrap. Compatibility and widescreen support vary by game and system setup.

## Build
Build with devkitPro devkitARM + libctru:
```sh
make
```
The build produces `nds-cia3dsx-converter.3dsx` (plus metadata files).

## SD card layout
The app creates this directory when launched:
```text
SD:/
└── converterNC3/
```
Generated game forwarders will be saved there in a later milestone.

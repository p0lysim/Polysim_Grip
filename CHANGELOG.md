# Changelog

All notable changes to this project are documented in this file.

## [Unreleased]

### Added
- 3MF print file: `cad/3mf/grip G1.3mf`.

### Changed
- STL files replaced with the correct printable parts: `export_linder_v2_1p`, `grip_singlepiece`,
  `jonction_v2`, `plate`, `spacer-one-piece`.
- Connection diagram redrawn from the grip and base PCB CAD: grip → GRIP_IN (Y encoder PCB) → GRIP (base PCB) → USB.
- README: single download table with repo folders, "Get the kit" section with the assembly video, shorter firmware and I2C sections.

## 2026-11 – STL parts and connection diagram

### Added
- One STL per printable part in `cad/stl/` (19 files, exported from Fusion revision v91).
- `cad/3mf/` folder for ready-to-print plates (empty for now).
- Connection diagram (`docs/images/wiring.svg`).
- Link to the Polysim Grip 3D printable kit.
- Arduino IDE upload procedure via the ICSP header.

### Changed
- Full assembly STEP moved to `cad/step/grip-g1.step`.
- README shortened; `docs/hardware.md` simplified around the connection diagram.

## 2026-11 – Repository reorganization

### Added
- Grip firmware (`firmware/polysim_grip/polysim_grip.ino`).
- Documentation: hardware overview and I2C protocol (`docs/`).
- Download links to Printables and Thingiverse (MakerWorld coming soon).

### Changed
- Repository reorganized into `cad/`, `firmware/` and `docs/`.
- `Grip G1 v91.step` renamed to `cad/grip-g1.step`.
- `Licence.md` renamed to `LICENSE.md`; removed a preamble copied from another project's license.

## [G1 – v91] – 2026-08-11

### Added
- First public release of the Grip G1 CAD assembly (Fusion revision v91).

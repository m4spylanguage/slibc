# 🕷️ slibc — Spider OS Standard C Library

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Standard: C23 / POSIX](https://img.shields.io/badge/Standard-C23%20%7C%20POSIX-orange.svg)](#features)
[![Architecture: x86_64](https://img.shields.io/badge/Arch-x86__64-brightgreen.svg)](#architecture)

**slibc** is a lightweight, zero-GPL, permissive standard C runtime and compatibility library engineered specifically for **Spider OS**. It provides modern C23 standards conformance, hardened fortification shims, POSIX/FTS tree traversal, and GNU extensions without the bloat, lock-in, or licensing constraints of glibc.

---

## 🚀 Key Features

* **100% Permissive (MIT Licensed):** Free from GPL viral constraints. Ideal for proprietary software, game engines, and permissive operating systems.
* **Modern C23 Standard Primitives:** Native implementations of ISO C23 functions including `memset_explicit`, `free_sized`, `free_aligned_sized`, `memalignment`, and unreachable semantics.
* **Hardened Security Fortification (`_FORTIFY_SOURCE`):** Full built-in buffer overflow detection wrappers for `__memcpy_chk`, `__memmove_chk`, `__memset_chk`, `__strcpy_chk`, `__strcat_chk`, `__sprintf_chk`, and `__snprintf_chk`.
* **POSIX & GNU Compatibility Shims:** Drop-in support for GNU extensions used by modern Linux utilities:
  * File Hierarchy Traversal (`fts_open`, `fts_read`, `fts_children`, `fts_set`, `fts_close`)
  * String & memory extensions (`strlcpy`, `strlcat`, `rawmemchr`, `strchrnul`, `mempcpy`)
  * Dynamic linker shims (`dl_iterate_phdr`, `dlinfo`, `dladdr1`)
  * Math and execution context extensions (`__exp10`, `__isoc23_strtol`, `__progname`)
* **Zero Overhead & Small Footprint:** Compiles into a single compact shared library (`libslibc.so.1`) measuring under 1MB.

---

## 📦 Directory Structure

```
slibc/
├── include/              # Public C headers
│   ├── slibc/
│   │   ├── c23.h         # C23 primitives & attributes
│   │   ├── chk.h         # Security checks & fortify prototypes
│   │   ├── fts.h         # File tree traversal API
│   │   └── gnu_compat.h  # GNU / glibc extension shims
│   └── slibc.h           # Master umbrella header
├── src/                  # Implementation sources
│   ├── c23.c             # C23 function implementations
│   ├── chk.c             # Fortified buffer-checked functions
│   ├── dl.c              # Dynamic loader interfaces
│   ├── fts.c             # File hierarchy traversal engine
│   └── gnu_compat.c      # GNU compatibility routines
├── slibc-gcc             # Compiler wrapper tool
├── Makefile              # Build automation
└── LICENSE               # MIT License
```

---

## 🛠️ Building & Installing

### Prerequisites
* A C compiler (`musl-gcc` or `gcc`)
* GNU Make

### Build
```bash
make -j$(nproc)
```
This produces `libslibc.so.1` and creates the `libslibc.so` symlink.

### Install
```bash
sudo make install
```
Installs `libslibc.so.1` into `/usr/local/lib/` and updates runtime links.

---

## 💻 Usage with `slibc-gcc`

`slibc-gcc` is a drop-in toolchain wrapper that compiles applications against `slibc` headers and shared objects:

```bash
./slibc-gcc -O2 main.c -o myapp
```

---

## 📄 License

`slibc` is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

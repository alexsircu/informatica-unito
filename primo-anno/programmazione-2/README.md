# How to compile

| Command                | Purpose                                                | Output                      |
| ---------------------- | ------------------------------------------------------ | --------------------------- |
| `make debug`           | Compiles the modules and generates `lib/libds_debug.a` | Static library (debug)      |
| `make release`         | Compiles with optimizations, generates `lib/libds.a`   | Library (release)           |
| `make executables`     | Compiles all `.c` files in `executables/`              | Executables in `bin/debug/` |
| `make run NAME=<file>` | Compiles and runs a single program                     | `bin/debug/<file>`          |
| `make clean`           | Removes build, lib, and bin directories                | —                           |
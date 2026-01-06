# How to compile

| Command                | Purpose                                                | Output                      |
| ---------------------- | ------------------------------------------------------ | --------------------------- |
| `make debug`           | Compiles the modules and generates `lib/libds_debug.a` | Static library (debug)      |
| `make release`         | Compiles with optimizations, generates `lib/libds.a`   | Library (release)           |
| `make executables`     | Compiles all `.c` files in `executables/`              | Executables in `bin/debug/` |
| `make run NAME=<file>` | Compiles and runs a single program                     | `bin/debug/<file>`          |
| `make clean`           | Removes build, lib, and bin directories                | —                           |

# Exercises

Turno 1 e turno 2 dell'esonero di Luglio 2025:
- executables/esonero-luglio-1.c
- executables/esonero-luglio-2.c

Turno 1 e turno 2 dell'esonero del 17 Dicembre 2025:
- executables/esonero-17-dec-turno-1.c
- executables/esonero-17-dec-turno-2.c

Esercizio 1 della lezione di laboratorio del [09/04/2025](https://unito.webex.com/recordingservice/sites/unito/recording/b78f9cf9f73f103dbedf020df05f9e0e/playback):
- implementare le funzioni insert, indexof ed indexesof
- dopo aver implementato le funzioni, creare implementazioni con void* al posto di int
- executables/09-04-main.c
- src/09-04-lista.c
- include/09-04-lista.h 

Prosegue esercizio usando void* al posto di un int val
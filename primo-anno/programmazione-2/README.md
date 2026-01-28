# How to compile

| Command                | Purpose                                                | Output                      |
| ---------------------- | ------------------------------------------------------ | --------------------------- |
| `make debug`           | Compiles the modules and generates `lib/libds_debug.a` | Static library (debug)      |
| `make release`         | Compiles with optimizations, generates `lib/libds.a`   | Library (release)           |
| `make executables`     | Compiles all `.c` files in `executables/`              | Executables in `bin/debug/` |
| `make run NAME=<file>` | Compiles and runs a single program                     | `bin/debug/<file>`          |
| `make clean`           | Removes build, lib, and bin directories                | —                           |

# Exercises

## Turno 1 e turno 2 dell'esonero di Luglio 2025:
- executables/esonero-luglio-1.c
- executables/esonero-luglio-2.c

## Turno 1 e turno 2 dell'esonero del 17 Dicembre 2025:
- executables/esonero-17-dec-turno-1.c
- executables/esonero-17-dec-turno-2.c

## Turno 1 della seconda parte dell'esame del 9 Giugno 2025:
- executables/seconda-parte-9-giu-turno-1-es1.c
- executables/seconda-parte-9-giu-turno-1-es2.c

## Esercizio 1 della lezione di laboratorio del [09/04/2025](https://unito.webex.com/recordingservice/sites/unito/recording/b78f9cf9f73f103dbedf020df05f9e0e/playback):
- implementare le funzioni insert, indexof ed indexesof
- dopo aver implementato le funzioni, creare implementazioni con void* al posto di int
- executables/09-04-main.c
- src/09-04-lista.c
- include/09-04-lista.h 

Prosegue esercizio usando void* al posto di un int val


## Esercizio 1 della lezione di laboratorio del [16/04/2025](https://unito.webex.com/webappng/sites/unito/recording/b0369444fcbf103d9dad0ae6cd7d5d44/playback):
- creare una lista di liste (un albero)
- le lista hanno un tag NORMALE o LISTA
- partendo dai file dell'esercizio 1 della lezione di laboratorio del 09/04/2025
- executables/16-04-main.c
- src/16-04-lista.c
- include/16-04-lista.h


## Esercizio 2 della lezione di laboratorio del [23/04/2025](https://unito.webex.com/webappng/sites/unito/recording/e4f67630023f103e999df641576a722a/playback):
- creare un albero che rappresenti le parole
- "baco" e "baro" scritte come 
```c
        -> c -> o
b -> a
        -> r -> o
```
- executables/23-04-main.c
- src/23-04-vocabolario.c
- include/23-04-vocabolario.h
- stessa struttura degli esercizi precedenti


## Esercizio 2.1 della lezione di laboratorio del [30/04/2025](https://unito.webex.com/webappng/sites/unito/recording/c089ddcfba354e74b01f531e908397d8/playback):
- albero binario bilanciato: come convertire una lista in un albero bilanciato
- executables/30-04-main.c
- src/30-04-bintree.c
- src/30-04-list.c
- include/30-04-bintree.h
- include/30-04-list.h


## Esercizio union della lezione di laboratorio del [07/05/2025](https://unito.webex.com/webappng/sites/unito/recording/45a590e59cc64bb491b5db7ae38699ed/playback):
- provare union e void* e vedere differenze
- include/07-05-list.h
- src/07-05-list.c
- src/07-05-unifinale.c
- executables/07-05-main.c
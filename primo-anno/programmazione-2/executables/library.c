#include <stdio.h>
#include <string.h>

#define TITLELENGTH 100
#define AUTHORSLENGTH 150
#define LISTLENGTH 50

typedef struct {
    char title[TITLELENGTH];
    char authors[AUTHORSLENGTH];
    int pages;
} book;

typedef struct {
    book list[LISTLENGTH];
    int number;
} library;

void init(library* lib);
void add_book(library* lib, char* title, char* author, int pages);
int full(library lib);

int main(void)
{
    library lib;    // static allocation

    init(&lib);
    add_book(&lib, "1984", "Orwell", 250);

    printf("Book in library: %d\n", lib.number);

    for (int i = 0; i < lib.number; i++)
    {
        printf("- %s\n", lib.list[i].title);
    }
}

void init(library* lib)
{
    lib->number = 0;
}

void add_book(library* lib, char* title, char* author, int pages)
{
    if (!full(*lib))
    {
        strcpy(lib->list[lib->number].title, title);
        strcpy(lib->list[lib->number].authors, author);
        lib->list[lib->number].pages = pages;

        lib->number++;
    }
    else
    {
        printf("The library is full\n");
    }
}

int full(library lib)
{
    return (lib.number == LISTLENGTH);
}

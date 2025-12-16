#include <stdio.h>

/**
 * @brief scrivere una funzione di confronto tra due file di testo.
 * tale funzione riceve in input i due filename e confronta i file carattere per carattere.
 * la funzione restituisce
 * -1 se vi sono errori nell'apertura dei file,
 * 0 (zero) se i due file sono identici, altrimenti
 * 1 se sono diversi e i due ultimi parametri contengono numero riga e carattere a cui si trova la differenza
 * creare anche un main() di richiama della funzione, che stampa il risultato.
 */

 int compare(char* fname1, char* fname2, long* line, long* charpos)
 {
    int cfp1;
    int cfp2;
    *line = 1;
    *charpos = 1;

    FILE* fp1 = fopen(fname1, "r");
    FILE* fp2 = fopen(fname2, "r");

    if (!fp1 || !fp2) return -1;

    while ((cfp1 = fgetc(fp1)) != EOF && (cfp2 = fgetc(fp2)) != EOF)
    {
        if (cfp1 != cfp2) 
        {
            fclose(fp1);
            fclose(fp2);
            return 1;
        }

        if (cfp1 == '\n')
        {
            (*line)++;
            *charpos = 1;
        }
        else
        {
            (*charpos)++;
        }
    }

    if (cfp1 != cfp2)
    {
        fclose(fp1);
        fclose(fp2);
        return 2;
    }

    return 0;
 }  

 int main(void)
 {
    long line;
    long charpos;

    int result = compare("/home/alexs/src/test1.txt", "/home/alexs/src/test2.txt", &line, &charpos);

    if (result == 2)
        printf("Do nothing\n");
    if (result == 1)
        printf("The differences are at line %ld at char position %ld\n", line, charpos);
    else if (result == 0)
        printf("The files are the same\n");
    else if (result == -1)
        printf("Error during file opening\n");
 }

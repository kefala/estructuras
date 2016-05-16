#include <stdlib.h>
#include <stdio.h>

void putCadena();
void initAlg();
char *invertirCadena();
char converToUpper();

int main() {
    FILE *archivo, *archivo2;
    int par = 0;
    char *temporal;

    archivo = fopen("texto.txt", "r");
    archivo2 = fopen("replace.txt", "w+");

    initAlg(archivo, archivo2, par);

    fclose(archivo);
    fclose(archivo2);
    return 0;
}

void initAlg (FILE *archivo, FILE *archivo2, int par) {
    char cadena[100];
    par = !par;

    if (fgets(cadena, 100, archivo) != 0) {
        putCadena(cadena, archivo2, par);
        initAlg(archivo, archivo2, par);
    }
}

void putCadena (char *cadena, FILE *archivo2, int par) {
    if (par) cadena = invertirCadena();
    fputs(cadena, archivo2);
}

char *invertirCadena (char *cadena) {
    int sizeOf, i, j;
    char *temporal;
    sizeOf = strlen(cadena);
    for (i=0,j = sizeOf-2; i < sizeOf/2; i++,j--) {
        temporal = converToUpper(cadena[i]);
        cadena[i] = converToUpper(cadena[j]);
        cadena[j] = temporal;
    }
    return cadena;
}

char converToUpper(int c) {
    return (c >= 'a' && c <= 'z')? c-32 : c;
}

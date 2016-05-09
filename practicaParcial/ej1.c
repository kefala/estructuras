#include <stdlib.h>
#include <stdio.h>

int main () {
    char *nomArchi = "archivo.txt", cadena[120], ch;
    FILE *file;
    file = fopen(nomArchi, "r+");

    if (file != NULL) {
        printf("EL archivo contiene: ");
        while( (ch=getc(file)) != EOF)
            printf("%c", ch);

        printf("\nIngrese dos lineas: ");
        int i = 0;
        while(i < 2) {
           fgets(cadena, 80, stdin);
           fputs(cadena, file);
           i++;
        }
        rewind(file);
        while( (ch=getc(file)) != EOF)
            printf("%c", ch);
        fclose(file);
    } else {
        printf("No se pudo abrir el archivo.");
    }
}

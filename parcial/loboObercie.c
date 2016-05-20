#include <stdlib.h>
#include <stdio.h>

void intAlg(FILE *, FILE *);
void putCadena(char *, FILE *);
char *getCadenaConPalabraMayus(char *);
char converToUpper(int);

int main() {
    FILE *archivo, *archivo2;
    char *temporal;

    archivo = fopen("texto.txt", "r");
    archivo2 = fopen("destino.txt", "w+");

    initAlg(archivo, archivo2);

    fclose(archivo);
    fclose(archivo2);
    return 0;
}

void initAlg (FILE *archivo, FILE *archivo2) {
    char cadena[100];

    if (fgets(cadena, 100, archivo) != 0) {
        putCadena(cadena, archivo2);
        initAlg(archivo, archivo2);
    }
}

void putCadena (char *cadena, FILE *archivo2) {
    cadena = getCadenaConPalabraMayus(cadena);
    fputs(cadena, archivo2);
}

char *getCadenaConPalabraMayus(char *cadena) {
    int i = 0, principioDePalabra = 0, finDePalabra = 0, longitudMax = 0, principioMax = 0, cicloFor;

    while (cadena[i]) {
        principioDePalabra = i;
        while (cadena[i] != ' ' && cadena[i]) {
            i++;
            finDePalabra = i;
        }
        if (finDePalabra  > principioDePalabra && (finDePalabra - principioDePalabra) > longitudMax && (finDePalabra - principioDePalabra) != 0) {
            principioMax = principioDePalabra;
            longitudMax = finDePalabra - principioDePalabra;
        }
        i++;
    }

    for(cicloFor = 0; cicloFor < longitudMax; cicloFor++)
        cadena[principioMax + cicloFor] = converToUpper(cadena[principioMax+ cicloFor]);

    cadena[i] = '\n';
    return cadena;
}

char converToUpper(int c) {
    return (c >= 'a' && c <= 'z')? c-32 : c;
}

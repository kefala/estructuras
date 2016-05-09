#include <stdlib.h>
#include <stdio.h>
#include "superLib.c"

int main () {
    FILE *file;
    file = getFile("archivo.txt", "r+");
    showFile(file);
}


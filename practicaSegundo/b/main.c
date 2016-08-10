#include <stdlib.h>
#include <stdio.h>

void meterCliente();

typedef struct {
    int cod_art;
    char *nom_art;
    float pre_art;
    int sto_Art;
    float gact_Art;
} regarti;
typedef struct {
    int cod_cli;
    char nom_cli[20];
    float cuenta;
} regcli;

int main () {
    //meterCliente();
    leerCliene();

    baja();
    return 0;
}


void meterCliente() {
    FILE *archivo;
    archivo = fopen("texto.dat", "a+b");
    char nom_cli[][20] = {"56"};

    regcli cliente;
    cliente.cod_cli = 12;
    cliente.cuenta = 12235;
    strcpy(cliente.nom_cli,nom_cli[0]);

    fwrite(&cliente, sizeof(cliente), 1, archivo);
    fclose(archivo);
}

void leerCliene() {
    FILE *archivo;
    archivo = fopen("texto.dat", "rb");

    regcli cliente;

    fread(&cliente, sizeof(cliente), 1, archivo);
    while(!feof(archivo)) {
        printf("%s \n", cliente.nom_cli);
        fread(&cliente, sizeof(cliente), 1, archivo);
    }

    fclose(archivo);
}

void baja() {
    FILE *archivo, *archivo2;
    archivo = fopen("texto.dat", "rb+");
    archivo2 = fopen("texto1.dat", "wb");

    regcli cliente;

    fread(&cliente, sizeof(cliente), 1, archivo);
    while(!feof(archivo)) {

        if (cliente.cod_cli != 1) {
            printf("%s \n", cliente.nom_cli);
            fwrite(&cliente, sizeof(cliente), 1, archivo2);
        }

        fread(&cliente, sizeof(cliente), 1, archivo);
    }

    fclose(archivo);

    remove("texto.dat");
    rename("texto1.dat","texto.dat");

}





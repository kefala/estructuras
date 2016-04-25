#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include <stdbool.h>
#include <termios.h>

#define WINDOWS 0
#define p printf
#define s scanf

typedef struct {
 int cod_art;
 char nom_art[30];
 float pre_art;
 int sto_art;
 float fact_art;
} regarti;

typedef struct {
 int cod_cli;
 char nom_cli[20];
 float cuenta;
} regcli;

int principalMenu(void);
int altasMenu(void);
void clearScreen(void);
void showAltasMenu(void);
void waitASecond(void);

void altaCliente(void);
void altaArticulos(void);
bool isSet(int, int);
int getStock(int);
void facturar(void);
void listar(int);


int main() {
    int op;
    srand(time(NULL));
    clearScreen();

    do {
        op = principalMenu();
        switch(op)
		{
            case 1: {
                showAltasMenu();
                break;
			}
			case 2: {
                facturar();
                break;
			}
            case 3: {
                listar(0);
                break;
            }
            case 4: {
                system("exit");
                break;
            }
        }
	} while (op < 4);

    return 0;
}

// FUNCIONES DE PANTALLA
int principalMenu(void) {
    int op;

 	do {
        clearScreen();
        p("\n\t\t  *****MENU PRINCIPAL*****\n\n");
        p("\n\n\t\t  - Altas \t\t <1>\n");
        p("\n\n\t\t  - Facturación\t\t <2>\n");
        p("\n\n\t\t  - Listados \t\t <3>\n");
        p("\n\n\t\t  - Salir           \t <4>\n");
        p("\n\n\n\t INGRESE OPCION: ");
        s("%d",&op);
	} while (op < 1 || op > 4);

    return(op);
}

int altasMenu(void) {
    int op;

 	do {
        clearScreen();
        p("\n\t\t  *****MENU PRINCIPAL*****\n\n");
        p("\n\n\t\t  - Alta de clientes \t\t <1>\n");
        p("\n\n\t\t  - Alta de articulos \t\t <2>\n");
        p("\n\n\t\t  - Volver atras \t\t <3>\n");
        p("\n\n\n\t INGRESE OPCION: ");
        s("%d",&op);
	} while (op < 1 || op > 3);

    return(op);
}

void showAltasMenu(void) {
    int op = 0;
    clearScreen();

    do {
        op = altasMenu();
        switch(op)
		{
            case 1: {
                altaCliente();
                break;
			}
			case 2: {
                altaArticulos();
                break;
			}
            case 3: {
                op = 4;
                break;
            }
        }
	} while (op < 3);
}

void clearScreen(void) {
    /*if (WINDOWS) system("cls");
    else system("clear");*/
}

void waitASecond(void) {
    system("stty cbreak -echo");
    getch();
    system("stty cooked echo");
}

// FUNCIONES DE APP
void altaCliente(void) {
    p("Pantala cliente \n\n");
    waitASecond();
}

void altaArticulos(void) {
    p("Pantala art \n\n");
}

bool isSet(int type, int id) {
    return false;
}

int getStock(int id) {
    return 0;
}

void facturar(void) {
    p("Pantala facturar \n\n");
}

void listar(int type) {
    p("Listar: %i \n\n", type);
}

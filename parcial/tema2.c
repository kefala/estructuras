#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define s scanf

void mostrar(FILE*);
void cargar(FILE*, FILE*);
int main()
{

 FILE *origen, *destino;
 char *nom1="texto.txt", *nom2="texto2.txt" ;
 int j,cuenta;
 system("cls");
 system("color 9f");
 origen=fopen(nom1,"r+");
 destino=fopen(nom2,"w+");
 //cargar(origen, destino);
 rewind(origen);
 p("\n Presione una tecla para visualizar el contenido del archivo origen:%s\n\n",nom1); getch();
 mostrar(origen); getch();
 rewind(destino);
 p("\n Presione una tecla para visualizar el contenido del archivo destino:%s\n\n",nom2); getch();
 mostrar(destino); getch();
 p("\n \nPresione una tecla para salir del Programa******");
 getch();
 system("cls");
 fclose(destino);
 fclose(origen);

 return(0);

}
void cargar(FILE *x,FILE*y)
{
   //Generar la Función
 }



void mostrar(FILE *x)
{
    char cad[81];
    while(fgets(cad,81,x)!=NULL)
              p("%s",cad);
}


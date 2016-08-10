#include <stdlib.h>
#include <stdio.h>

struct regarti {
int cod_art;
char nom_art[20];
float pre_art;
int sto_art;
float fact_art;
};
struct regcli {
int cod_cli;
char nom_cli[20];
float cuenta;
};


void inicio(FILE*,FILE*);
void ingresar(FILE*,FILE*);
void mostrar(FILE*,FILE*);
int error(char*);
void tecla(void);
void linea(int);
int main()
{
	FILE *cli,*art;
	char *nomarchcli="c:\\clientes.dat";
	char *nomarchart="c:\\articulos.dat";
	system("cls");
	if((cli=fopen(nomarchcli,"wb+"))==NULL)
		exit(error(nomarchcli));
	p("\nEl archivo %s ha sido cargado!!",nomarchcli);

	if((art=fopen(nomarchart,"wb+"))==NULL)
		exit(error(nomarchart));
	p("\nEl archivo %s ha sido cargado!!",nomarchart);
	tecla();
	inicio(cli,art);
	system("cls");
	ingresar(cli,art);
	mostrar(cli,art);
	linea(80);
	tecla();            //lo muestro
	fclose(cli);fclose(art);
	return(0);

}
void linea(int x)
{
 int i;
     for(i=1;i<x;i++)
	 p("*");

}

void inicio(FILE *x,FILE*y)
{
 struct regcli c;
 struct regarti a;
 char nomcli[][20]={"Lopez","Rodriguez","Garcia","Martinez","Loli"};
 char nomart[][20]={"Coca Cola","Agua T¢nica","N.Fanta","Sprite","Pomelo","Mandarina"};
 float pre[]={12.70,13.75,13.66,12.80,12.89,13.01};
 int i;
 // Inicializar los archivos de Registros

}

void mostrar(FILE *x,FILE*y)
{
	struct regcli c;
	struct regarti a;
	rewind(x);
	system("cls");
	p("\n\n\t\t\t Nomina de Clientes\n");
	linea(80);
	p("\nCodigo\tNombre\t\t\t\t\t\tSaldo\n");
	fread(&c,sizeof(c),1,x);
	while(!feof(x))
	{
		p("\n%3d\t%-20s\t\t\t\t%6.2f",c.cod_cli,c.nom_cli,c.cuenta);
		fread(&c,sizeof(c),1,x);
	}
	p("\n");
	rewind(y);
	linea(80);
	p("\n\n\t\t\t Nomina de Articulos\n");
	linea(80);
	p("\nCodigo\tArticulo\t\t\tStock\t\tFacturacion\n");
	fread(&a,sizeof(a),1,y);
	while(!feof(y))
	{
		p("\n%3d\t%-20s\t\t%3d\t\t%8.2f\n",a.cod_art,a.nom_art,a.sto_art,a.fact_art);
		fread(&a,sizeof(a),1,y);
	}

}

void ingresar(FILE *cl,FILE*ar)
{
// ingresar datos
}

int error(char *x)
{
	fprintf(stderr,"no se puede abrir el archivo %s",x);
	return(1);
}
void tecla(void)
{
	p("\nPresione cualquier tecla para continuar!!!");
	system('pause');
}







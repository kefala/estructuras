#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct
{
	char calle[30];
	int nro;
	char localidad[30];
	char codpost[10];
}direccion;

typedef struct
{
	char apellido[20];
	char nombre[20];
	fecha fechanac;
	direccion dire;
	char fono1[15];
	char fono2[15];
	char fono3[15];
	char vigencia;
}persona;

int menu(void);
void alta(void);
void baja(void);
void modifica(void);
void buscar(void);
void listar(void);
persona ingresar_datos(void);
int menubus(void);
void busqueda(char*,int);
int menu_bajas();
void baja_logica(void);
void baja_fisica();
void listado_de_bajas(void);
main()
{
	int op;
	do
	{
		op=menu();
		switch(op)
		{
			case 1:
				alta();
				break;
			case 2:
				baja();
				break;
			case 3:
				modifica();
				break;
			case 4:
				buscar();
				break;
			case 5:
				listar();
				break;
		}
	}while(op<6);
	return 0;
}

void alta(void)
{
	persona reg;
	FILE *p1;

	p1=fopen("c:\\agenda","a+b");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}

	reg= ingresar_datos();

	fwrite(&reg,sizeof(reg),1,p1);

	fclose(p1);
}

persona ingresar_datos(void)
{
	persona reg;

	clrscr();
	printf("DATOS DE LA PERSONA A INGRESAR	\n\n");

	printf("Datos Personales\n\n");
	fflush(stdin);
	printf("Apellido: ");gets(reg.apellido);
	printf("Nombre: ");gets(reg.nombre);
	printf("Fecha de nacimiento\n");
	printf("D¡a: ");scanf("%d",&reg.fechanac.dia);
	printf("Mes: ");scanf("%d",&reg.fechanac.mes);
	printf("A¤o: ");scanf("%d",&reg.fechanac.anio);
	fflush(stdin);

	printf("Direccion\n\n");
	printf("Calle: ");gets(reg.dire.calle);
	printf("N£mero: ");scanf("%d",&reg.dire.nro);
	fflush(stdin);
	printf("Localidad: ");gets(reg.dire.localidad);
	printf("Codigo Postal: ");gets(reg.dire.codpost);

	printf("Telefonos\n\n");
	printf("Telefono 1: ");gets(reg.fono1);
	printf("Telefono 2: ");gets(reg.fono2);
	printf("Telefono 3: ");gets(reg.fono3);

	return reg;
}
int menu(void)
{
	int op;

	do
	{
		clrscr();
		gotoxy(38,5);
		printf("MENU");
		gotoxy(36,8);
		printf("1- Alta");
		gotoxy(36,9);
		printf("2- Baja");
		gotoxy(36,10);
		printf("3- Modificar datos");
		gotoxy(36,11);
		printf("4- Busqueda");
		gotoxy(36,12);
		printf("5- Listado");
		gotoxy(36,13);
		printf("6- Salir");
		gotoxy(36,15);
		printf("Ingrese una opcion: ");
		scanf("%d",&op);
	}while(op<1||op>6);

	return op;
}

void baja(void)
{
	int op;
	do
	{
		op=menu_bajas();
		switch(op)
		{
			case 1:
				baja_logica();
				break;
			case 2:
				baja_fisica();
				break;
			case 3:
				listado_de_bajas();
				break;
		}
	}while(op<4);
}
int menu_bajas(void)
{
	int op;

	do
	{
		clrscr();
		gotoxy(38,5);
		printf("MENU");
		gotoxy(34,8);
		printf("1- Baja Logica (no elimina registro)");
		gotoxy(34,9);
		printf("2- Baja Fisica (elimina registr)");
		gotoxy(34,10);
		printf("3- Listado de Bajas");
		gotoxy(34,11);
		printf("4- Salir");

		gotoxy(34,13);
		printf("Ingrese una opcion: ");
		scanf("%d",&op);
	}while(op<1||op>4);

	return op;
}

void baja_logica(void)
{
	int c=0,s,x;
	persona reg;
	FILE	*p1;
	char buscado[30],b,cad[30];

	p1=fopen("c:\\agenda","r+b");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}
		do
		{
			clrscr();
			printf("BAJA LOGICA\n\n");
			printf("                    <1>Buscar por apellido <2> Buscar por nombre");
			printf("\n\nIngrese opcion: ");
			scanf("%d",&x);
		}while(x<1 || x>2);

		if(x==1)strcpy(cad,"apellido");
		else strcpy(cad,"nombre");

		printf("\n\n                        Ingrese el %s a buscar: ",cad);
		fflush(stdin);
		gets(buscado);

		fread(&reg,sizeof(reg),1,p1);
		c=0;
		while(!feof(p1))
		{
			s=0;
			switch(x)
			{
				case 1:
					if(strcmp(strlwr(buscado),strlwr(reg.apellido))==0)
						s=1;
				case 2:
					if(strcmp(strlwr(buscado),strlwr(reg.nombre))==0)
						s=1;
			}
			if(s==1)
			{
				clrscr();
				printf("DATOS DEL REGISTRO ENCONTRADO	\n\n");

				printf("Datos Personales\n");
				printf("\n        Apellido     : %s ",reg.apellido);
				printf("\n        Nombre       : %s ",reg.nombre);

				printf("\n    Direccion");
				printf("\n        Calle        : %s",reg.dire.calle);
				printf("\n        N£mero       : %d",reg.dire.nro);
				printf("\n        Localidad    : %s",reg.dire.localidad);
				printf("\n        Codigo Postal: %s",reg.dire.codpost);

				do
				{
					printf("\n\nConfirma la baja <s> <n> : ");
					scanf("%c",&b);
				}while(!(tolower(b)=='s' || tolower(b)=='n'));
				if(b=='n')
					break;
				else
				{
					reg.vigencia='X';
					fseek(p1,c*sizeof(persona),SEEK_SET);
					fwrite(&reg,sizeof(reg),1,p1);
					break;
				}
			}
			fread(&reg,sizeof(reg),1,p1);
			c++;
		}
	if(s==0 && feof(p1))
	{
		clrscr();
		printf("REGISTRO NO ENCONTRADO");
		printf("\n\nPulse una tecla...");
		getch();
	}
	fclose(p1);
}
void baja_fisica(void)
{
	int c=0;
	persona reg;
	FILE	*p1,*p2,*p3;

	p1=fopen("c:\\agenda","rb");
	p2=fopen("c:\\agenda1","wb");
	p3=fopen("c:\\bajas","ab");

	if(p1==NULL||p2==NULL||p3==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}

	fread(&reg,sizeof(reg),1,p1);

	while(!feof(p1))
	{
		if(reg.vigencia=='X')
		{
			fwrite(&reg,sizeof(reg),1,p3);
			c++;
		}
		else
			fwrite(&reg,sizeof(reg),1,p2);

		fread(&reg,sizeof(reg),1,p1);
	}
	clrscr();
	printf("\n\n                   Se dieron de baja %d registros",c);
	printf("\n\nPulse una tecla...");
	getch();

	fclose(p1);
	fclose(p2);
	fclose(p3);

	remove("c:\\agenda");
	rename("c:\\agenda1","c:\\agenda");

}

void listado_de_bajas(void)
{
	persona reg;
	FILE *p1;
	p1=fopen("c:\\bajas","rb");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}

	fread(&reg,sizeof(reg),1,p1);
	while(!feof(p1))
	{
			clrscr();
			printf("DATOS DE LAS PERSONAS DADAS DE BAJA	\n\n");

			printf("Datos Personales\n");
			printf("\n        Apellido     : %s ",reg.apellido);
			printf("\n        Nombre       : %s ",reg.nombre);
			printf("\n    Fecha de nacimiento");
			printf("\n        D¡a          : %d",reg.fechanac.dia);
			printf("\n        Mes          : %d",reg.fechanac.mes);
			printf("\n        A¤o          : %d",reg.fechanac.anio);

			printf("\n    Direccion");
			printf("\n        Calle        : %s",reg.dire.calle);
			printf("\n        N£mero       : %d",reg.dire.nro);
			printf("\n        Localidad    : %s",reg.dire.localidad);
			printf("\n        Codigo Postal: %s",reg.dire.codpost);

			printf("\n    Telefonos");
			printf("\n        Telefono 1   : %s",reg.fono1);
			printf("\n        Telefono 2   : %s",reg.fono2);
			printf("\n        Telefono 3   : %s",reg.fono3);

			printf("\n\nPulse una tecla...");
			getch();

			fread(&reg,sizeof(reg),1,p1);
	}

	fclose(p1);
}


void modifica(void)
{
	int c=0,s,x;
	persona reg;
	FILE	*p1;
	char buscado[30],b,cad[30];

	p1=fopen("c:\\agenda","r+b");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}
		do
		{
			clrscr();
			printf("RUTINA DE ACTUALIZACION DE DATOS\n\n");
			printf("                    <1>Buscar por apellido <2> Buscar por nombre");
			printf("\n\nIngrese opcion: ");
			scanf("%d",&x);
		}while(x<1 || x>2);

		if(x==1)strcpy(cad,"apellido");
		else strcpy(cad,"nombre");

		printf("\n\n                        Ingrese el %s a buscar: ",cad);
		fflush(stdin);
		gets(buscado);

		fread(&reg,sizeof(reg),1,p1);
		c=0;
		while(!feof(p1))
		{
			s=0;
			switch(x)
			{
				case 1:
					if(strcmp(strlwr(buscado),strlwr(reg.apellido))==0)
						s=1;
				case 2:
					if(strcmp(strlwr(buscado),strlwr(reg.nombre))==0)
						s=1;
			}
			if(s==1 && reg.vigencia!='X')
			{
				clrscr();
				printf("DATOS DEL REGISTRO ENCONTRADO	\n\n");

				printf("Datos Personales\n");
				printf("\n        Apellido     : %s ",reg.apellido);
				printf("\n        Nombre       : %s ",reg.nombre);

				printf("\n    Direccion");
				printf("\n        Calle        : %s",reg.dire.calle);
				printf("\n        N£mero       : %d",reg.dire.nro);
				printf("\n        Localidad    : %s",reg.dire.localidad);
				printf("\n        Codigo Postal: %s",reg.dire.codpost);

				do
				{
					printf("\n\nConfirma la MODIFICACION <s> <n> : ");
					scanf("%c",&b);
				}while(!(tolower(b)=='s' || tolower(b)=='n'));
				if(b=='n')
					break;
				else
				{
					do
					{
						clrscr();
						printf("NUEVOS DATOS DE LA PERSONA	\n\n");

						printf("Datos Personales\n\n");
						fflush(stdin);
						printf("Apellido: ");gets(reg.apellido);
						printf("Nombre: ");gets(reg.nombre);
						printf("Fecha de nacimiento\n");
						printf("D¡a: ");scanf("%d",&reg.fechanac.dia);
						printf("Mes: ");scanf("%d",&reg.fechanac.mes);
						printf("A¤o: ");scanf("%d",&reg.fechanac.anio);
						fflush(stdin);

						printf("Direccion\n\n");
						printf("Calle: ");gets(reg.dire.calle);
						printf("N£mero: ");scanf("%d",&reg.dire.nro);
						fflush(stdin);
						printf("Localidad: ");gets(reg.dire.localidad);
						printf("Codigo Postal: ");gets(reg.dire.codpost);

						printf("Telefonos\n\n");
						printf("Telefono 1: ");gets(reg.fono1);
						printf("Telefono 2: ");gets(reg.fono2);
						printf("Telefono 3: ");gets(reg.fono3);
						do
						{
							printf("\n\nConfirma datos <s/n>: ");
							scanf("%c",&b);
						}while(!(tolower(b)=='s' || tolower(b)=='n'));
					}while(tolower(b)=='n');
					fseek(p1,c*sizeof(reg),SEEK_SET);
					fwrite(&reg,sizeof(reg),1,p1);
					break;
				}
			}
			fread(&reg,sizeof(reg),1,p1);
			c++;
		}
	if(s==0 && feof(p1))
	{
		clrscr();
		printf("REGISTRO NO ENCONTRADO");
		printf("\n\nPulse una tecla...");
		getch();
	}
	fclose(p1);


}
void buscar(void)
{
	int op;
	do
	{
		op=menubus();
		switch(op)
		{
			case 1:
				busqueda("Apellido",1);
				break;
			case 2:
				busqueda("Nombre",2);
				break;
		}
	}while(op<3);
}

int menubus(void)
{
	int op;

	do
	{
		clrscr();
		gotoxy(38,5);
		printf("MENU");
		gotoxy(34,8);
		printf("1- Buscar por Apellido");
		gotoxy(34,9);
		printf("2- Buscar por Nombre");
		gotoxy(34,10);
		printf("3- Salir");
		gotoxy(34,12);
		printf("Ingrese una opcion: ");
		scanf("%d",&op);
	}while(op<1||op>3);

	return op;
}

void busqueda(char *cad,int x)
{
	persona reg;
	FILE	*p1;
	char buscado[30],b;
	int s;

	p1=fopen("c:\\agenda","rb");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}

		clrscr();
		printf("BUSQUEDA EN LA AGENDA\n\n");
		printf("Ingrese el %s a buscar: ",cad);
		fflush(stdin);
		gets(buscado);

		fread(&reg,sizeof(reg),1,p1);

		while(!feof(p1))
		{
			s=0;
			switch(x)
			{
				case 1:
					if(strcmp(strlwr(buscado),strlwr(reg.apellido))==0)
						s=1;
				case 2:
					if(strcmp(strlwr(buscado),strlwr(reg.nombre))==0)
						s=1;
			}

			if(s==1 && reg.vigencia!='X')
			{
				clrscr();
				printf("DATOS DEL REGISTRO ENCONTRADO	\n\n");

				printf("Datos Personales\n");
				printf("\n        Apellido     : %s ",reg.apellido);
				printf("\n        Nombre       : %s ",reg.nombre);
				printf("\n    Fecha de nacimiento");
				printf("\n        D¡a          : %d",reg.fechanac.dia);
				printf("\n        Mes          : %d",reg.fechanac.mes);
				printf("\n        A¤o          : %d",reg.fechanac.anio);

				printf("\n    Direccion");
				printf("\n        Calle        : %s",reg.dire.calle);
				printf("\n        N£mero       : %d",reg.dire.nro);
				printf("\n        Localidad    : %s",reg.dire.localidad);
				printf("\n        Codigo Postal: %s",reg.dire.codpost);

				printf("\n    Telefonos");
				printf("\n        Telefono 1   : %s",reg.fono1);
				printf("\n        Telefono 2   : %s",reg.fono2);
				printf("\n        Telefono 3   : %s",reg.fono3);
				do
				{
					printf("\n\nContinua la busqueda <s> <n> : ");
					scanf("%c",&b);
				}while(!(tolower(b)=='s' || tolower(b)=='n'));
				if(b=='n')
				{
					break;
				}
			}
			fread(&reg,sizeof(reg),1,p1);
		}
	if(s==0 && feof(p1))
	{
		clrscr();
		printf("REGISTRO NO ENCONTRADO");
		printf("\n\nPulse una tecla...");
		getch();
	}
	fclose(p1);
}


void listar(void)
{
	persona reg;
	FILE *p1;
	p1=fopen("c:\\agenda","a+b");
	if(p1==NULL)
	{
		clrscr();
		gotoxy(22,10);
		printf("ERROR EN APERTURA DE ARCHIVO");
		getch();
		exit(1);
	}

	fread(&reg,sizeof(reg),1,p1);
	while(!feof(p1))
	{
		if(reg.vigencia!='X')
		{
			clrscr();
			printf("DATOS DE LAS PERSONAS	\n\n");

			printf("Datos Personales\n");
			printf("\n        Apellido     : %s ",reg.apellido);
			printf("\n        Nombre       : %s ",reg.nombre);
			printf("\n    Fecha de nacimiento");
			printf("\n        D¡a          : %d",reg.fechanac.dia);
			printf("\n        Mes          : %d",reg.fechanac.mes);
			printf("\n        A¤o          : %d",reg.fechanac.anio);

			printf("\n    Direccion");
			printf("\n        Calle        : %s",reg.dire.calle);
			printf("\n        N£mero       : %d",reg.dire.nro);
			printf("\n        Localidad    : %s",reg.dire.localidad);
			printf("\n        Codigo Postal: %s",reg.dire.codpost);

			printf("\n    Telefonos");
			printf("\n        Telefono 1   : %s",reg.fono1);
			printf("\n        Telefono 2   : %s",reg.fono2);
			printf("\n        Telefono 3   : %s",reg.fono3);

			printf("\n\nPulse una tecla...");
			getch();
		}
			fread(&reg,sizeof(reg),1,p1);
	}

	fclose(p1);
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define p printf
#define s scanf

/*
    ESTO ESTÁ PREPARADO PARA SOLO PARA LINUX, VIVA LA COMUNIDAD, MUERTE A WINDORRRRRRRR


    LA FUNCION GETS NO FUNCIONA POR LO TANTO USO SCANF, SE QUE NO LO ES LO MISMO PERO TENGO HAMBRE.
*/


typedef struct
{
 int cod_ciu;
 char nom_ciu[30];
 float t_min;
 float t_max;
 float dif_t;
 } registro;

float mostrar(FILE *);
void tecla(void);
void cargar(FILE *);
void filtrar(FILE*,FILE*);
void maxamp(FILE*,float);
int error(char *);
int malCodigoDeCiudad(FILE *, int);

int main()
{
    FILE *arch;
    float max;
    char *nomarch = "temp.dat";


    if((arch=fopen(nomarch,"ab+")) == NULL) exit(error(nomarch));

    p("\nEl archivo %s ha sido abierto para escritura!!!",nomarch);

    tecla();

    cargar(arch);

    p("\n Presione una tecla para mostrar la Estadística de Temperaturas !!!\n\n");

    tecla();

    max = mostrar(arch);

    p("\n La amplitud maxima es %.2f corresponde a:\n\n ",max);

    maxamp(arch,max);

    fclose(arch);

    return(0);
}
int error(char *x)
{
	fprintf(stderr,"No se pudo abrir el archivo %s",x);
	return(1);
}
void tecla(void)
{
    int num;
    p("\nPresione un numero para continuar !!!!\n");
    s("%d", &num);

    system("clear");
}

void cargar(FILE *x)
{
	registro r;
	int continuar, guardar;

    p("\nDesea ingresar un registro?\nIngrese 0 para salir o cualquier numero para continuar\n");
    s("%d", &continuar);


    while(continuar) {
        system("clear");
        p("\nIngrese codigo de la ciudad: ");
        s("%d", &r.cod_ciu);
        while (malCodigoDeCiudad(x, r.cod_ciu)) {
            printf("\n\nTonto mono estupido, el codigo de ciudad ya existe, inventa otro");
            p("\nIngrese codigo de la ciudad: ");
            s("%d", &r.cod_ciu);
        }
        p("\nIngrese nombre de la ciudad: ");
        s("%s", &r.nom_ciu);
        p("\nIngrese temperatura mínima de la ciudad: ");
        s("%f", &r.t_min);
        p("\nIngrese temperatura maxima de la ciudad: ");
        s("%f", &r.t_max);

        while (r.t_max < r.t_min) {
            p("\Ingrese las temperaturas correctas: \n\n");
            p("\nIngrese temperatura mínima de la ciudad: ");
            s("%f", &r.t_min);
            p("\nIngrese temperatura maxima de la ciudad: ");
            s("%f", &r.t_max);
        }
        system("clear");
        r.dif_t = r.t_max - r.t_min;
        p("\Estos son los datos ingresados\n ");
        p("\nCodigo de ciudad: \t%d", r.cod_ciu);
        p("\nNombre de la ciudad: \t%s", r.nom_ciu);
        p("\nTemperatura mínima: \t%f", r.t_min);
        p("\nTemperatura maxima: \t%f", r.t_max);
        p("\nAmplitud terminaca: \t%f", r.dif_t);
        p("\nDesea guardarlo? \nIngrese 0 para salir o cualquier numero para continuar\n");
        s("%d", &guardar);
        system("clear");

        if (guardar) {
            fwrite(&r, sizeof(r), 1, x);
            p("Se guardo con exito");
        }

        p("\n\nDesea ingresar un registro?\nIngrese 0 para salir o cualquier numero para continuar\n");
        s("%d", &continuar);
    }


}
float mostrar(FILE *x)
{
	registro r;
	float maxi = 0;
	rewind(x);

	p("\n \t\t\tESTADISTICA DE TEMPERATURA DE CIUDADES \n\n");
	p("\n Cod \t CIUDAD\t\t\t MINIMA   MAXIMA\t\tAMPLITUD\n\n\n");

	fread(&r, sizeof(r) , 1, x);
	while(!feof(x)) {
		if(r.dif_t > maxi) maxi = r.dif_t;

		p("\n %-10d%-20s %6.2f\t  %6.2f\t\t%6.2f\n\n",r.cod_ciu,r.nom_ciu,r.t_min,r.t_max,r.dif_t);

        fread(&r, sizeof(r), 1, x);
    }

	return(maxi);
}

void maxamp(FILE*x, float y)	{
    registro r;
    rewind(x);

    fread(&r, sizeof(r) , 1, x);
    p("La/s ciudad/es que se llama/n \n");
	while(!feof(x)) {
        if (r.dif_t == y) p("\t%s\n", r.nom_ciu);

        fread(&r, sizeof(r), 1, x);
    }
}

int malCodigoDeCiudad(FILE *x, int codCiu)
{
	registro r;
	rewind(x);

	fread(&r, sizeof(r) , 1, x);
	while(!feof(x)) {
		if(r.cod_ciu == codCiu) return 1;
        fread(&r, sizeof(r), 1, x);
    }

	return 0;
}

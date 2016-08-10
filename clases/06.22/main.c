#include<stdio.h> // pila dinámica común con menú
#include<stdlib.h>

typedef struct elemento
{
	int nro;
	struct elemento * sig;
} nodo;

nodo* ingresarDato(void);
int pilaVacia(nodo*);

void apilar(nodo**,nodo*);
nodo desapilar(nodo**);

void mostrarDato(nodo);
void listarPila(nodo*);
void eliminarPila(nodo*);

int menu(void);
void listar(nodo*);
int main()
{
 nodo *p,*q,dato;
 int op;
  p=NULL;
    do
	 {
		op=menu();
		switch(op)
		{
            case 1:
				q=ingresarDato();
				apilar(&p,q);
				break;
			 case 2:
				if(pilaVacia(p))
					{
                      dato=desapilar(&p);
					  mostrarDato(dato);
					}
						break;
			 case 3:
				if(pilaVacia(p))
				{
	             printf("CONTENIDO DE LA PILA\n\n");
				  listarPila(p);
				}
		}
	 }while(op<4);

	 if(p!=NULL)
			eliminarPila(p);

	 return 0;
}

nodo* ingresarDato(void)
{
	int nro;
	 nodo *q;
	 q=(nodo*)malloc(sizeof(nodo));
	 printf("\n\nIngrese un n£mero:  ");
	 scanf("%d",&nro);
	 q->nro=nro;
	 return q;
}


int pilaVacia(nodo*p)
{
    if(p==NULL)
	 {
		printf("PILA VACIA\n\n");
		system("pause");
		return 0;
	 }
	 else return 1;
}

void apilar(nodo**p,nodo*q)
{
	 q->sig=*p;
	*p=q;
}

nodo desapilar(nodo**p)
{
	nodo dato,*aux;
    aux=*p;
	dato=**p;
	*p=(*p)->sig;
	 free(aux);
	 return dato;
}

void mostrarDato(nodo dato)
{
	 printf("\n\n\nDato desapilado: %ld",dato.nro);
	 printf("\n\n");
	 system("pause");
}



void listarPila(nodo*p)
{
  if(p)
	 {
		printf("%d\n",p->nro);
		listarPila(p->sig);
	 }
}


void eliminarPila(nodo*p)
{
	nodo *aux;
	 while(p)
	 {
		aux=p;
			p=p->sig;
			free(aux);
	 }
}

int menu(void)
{
	int op;
	 do
	 {
		printf("\n\t\t\t MENU DE OPCIONES (LISTAS)\n\n");
		printf("\n\n\t\t\t - Apilar Datos      <1>\n");
		printf("\n\n\t\t\t - Desapilar Datos   <2>\n");
		printf("\n\n\t\t\t - Listar Datos      <3>\n");
		printf("\n\n\t\t\t - Salir             <4>\n");
		printf("\n\n\t\t\tIngrese Opcion:  ");
		scanf("%d",&op);
	 }while(op<1||op>4);
	 return op;
}

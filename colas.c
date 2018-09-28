#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
	int dato;
	struct Nodo * siguiente;
}COLA;

COLA *front, *back;
int cont;

void inicializar(){
	front=back=NULL;
	cont=0;
}

int es_vacia(){
	return ((front==NULL)&&(back==NULL));
}

int num_ite(){
	return cont;
}

void enqueue(int valor){
	COLA *temp;
	if(back==NULL){
		//si no hay elementos en la cola
		back=(COLA *)malloc(sizeof(COLA));
		back->siguiente=NULL;
		back->dato=valor;
		front=back;
	}else{
		//cuando hay elementos en la cola
		temp=(COLA *)malloc(sizeof(COLA));
		back->siguiente=temp;
		temp->dato=valor;
		temp->siguiente=NULL;
		back=temp;
	}
	cont++;
}

int dequeue(){
	COLA *temp=front;
	int item;
	if(front==NULL){
		printf("\nNo hay elementos\n");
		system("pause");
		}else{
			if(temp->siguiente != NULL){
				//La cola tiene mas de un elemento
				item=temp->dato;
				temp=temp->siguiente;
				free(front);
				front=temp;
			}else{
				//La cola solo tiene un dato
				item=temp->dato;
				free(front);
				front=back=NULL;
			}
	}
	cont--;
}

int main(int argc, char *argv[]){
	int opcion, valor, elementos;
	
	
	do{
		system("cls");
		printf("\n[1] Insertar un elemento.");
		printf("\n[2] Borrar elemento.");
		printf("\n[3] Desplegar primer elemento.");
		printf("\n[4] Desplegar ultimo elemento.");
		printf("\n[5] Numero de elementos.");
		printf("\n[6] Verificar elementos.");
		printf("\n[7] Salir.");
		printf("\nInserte su opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: printf("\nDigite el valor a guardar: ");
					scanf("%d",&valor);
					enqueue(valor);
					break;
			case 2: dequeue();
					break;
			case 3: printf("\nPrimer elemento: %d\n",front->dato);
					system("pause");
					break;
			case 4: printf("\nUlttimo elemento: %d\n",back->dato);
					system("pause");
					break;
			case 5: printf("\nNumero de elementos: %d\n",num_ite());
					system("pause");
					break;
			case 6: if(es_vacia()){
						printf("\nNo hay elementos.\n");
						system("pause");
					}else{
						printf("\nElementos existentes.\n");
						system("pause");
					}
					break;
			case 7: exit(0);
			default: printf("\nOpcion invalida. Trate de nuevo.");
		}
	}while(opcion != 7);
	
	
	
}













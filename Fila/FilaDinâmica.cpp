#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no NO;
struct no{
	int dado;
	NO *proximo;
};

typedef struct fila{
	NO *inicio;
	NO *fim;
}FILA;

void inicializaFila(FILA *fila){
	fila->inicio=NULL;
	fila->fim=NULL;
}

void enfileirar(int dado, FILA *fila){
	NO *ptr = (NO*)malloc(sizeof(NO));
	if (ptr==NULL){
		printf("Erro de Alocação\n");
		return;
	}else{
		ptr->dado=dado;
		ptr->proximo=NULL;
		if (fila->inicio==NULL)
		{
			fila->inicio=ptr;
		}else{
			fila->fim->proximo=ptr;
		}
		fila->fim=ptr;
		return;
	}
}

int desenfileirar(FILA *fila){
	NO *ptr = fila->inicio;
	int dado;
	if (ptr != NULL){
		printf("Dado removido: %i\n", ptr->dado);
		fila->inicio = ptr->proximo;
		ptr->proximo=NULL;
		dado = ptr->dado;
		free(ptr);
		if (fila->inicio==NULL){
			fila->fim = NULL;
		}
		return dado;
	}else{
		printf("Fila Vazia\n");
		return 0;
	}
}

void imprimirFila(FILA *fila){
	NO *ptr = fila->inicio;
	if (ptr!=NULL){
		while(ptr!=NULL){
			printf("Dado: %i\n", ptr->dado);
			ptr=ptr->proximo;
		}
	}else{
		printf("Fila Vazia\n");
		return;
	}
}

int main(){
	
	FILA *f1 = (FILA*)malloc(sizeof(FILA));
	if (f1 == NULL){
		printf("Erro de Alocação");
	}else{
		inicializaFila(f1);
		enfileirar(10, f1);
		enfileirar(20, f1);
		enfileirar(30, f1);
		imprimirFila(f1);
		desenfileirar(f1);
		desenfileirar(f1);
		desenfileirar(f1);
		imprimirFila(f1);
	}
	return 0;
}
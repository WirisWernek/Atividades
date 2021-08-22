#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



struct TipoCelula{
	int item;
	TipoCelula *proximo;
};
int Pilha_Contador;
TipoCelula *Topo;




bool Pilha_Construtor(){
	Topo = NULL;
	Pilha_Contador=0;
}


/*
Método Desnecessário
bool Pilha_Cheia(){

}*/
bool Pilha_Vazia(){
	if(Topo==NULL){
		return true;
	}else{
		return false;
	}
}


bool Pilha_Destrutor(){
	int aux;
	TipoCelula *temp;
	if (Pilha_Vazia())
	{
		return false;	
	}else{
		while(Topo!=NULL){
			temp =Topo;
			temp=temp->proximo=NULL;

			Topo=Topo->proximo;
			free(temp);
		}
		Pilha_Contador=0;
		return true;
	}
}

int Pilha_Tamanho(){
	return Pilha_Contador;
}


bool Pilha_Push(int valor){
	TipoCelula *Nova_celula=(TipoCelula *)malloc(sizeof(TipoCelula));
	if(Nova_celula==NULL){//caso o SO não forneça memória
		return false;
	}else{
		Nova_celula->item=valor;
		Nova_celula->proximo=Topo;
		Topo=Nova_celula;
		Pilha_Contador++;
		printf("O valor %i foi adicionado ao topo\n", valor);
		return true;
	}
}


bool Pilha_Pop(int &valor){
	TipoCelula *temp;
	if (Pilha_Vazia())
	{
		return false;	
	}else{
		valor = Topo->item;
		printf("O valor removido do topo é %i\n", valor);
		temp = Topo;
		Topo=Topo->proximo;

		temp->proximo=NULL; //Medida de segurança para descontinuar a célula
		free(temp);
		Pilha_Contador--;
		return true;
	}

}
bool Pilha_Get(int &valor){
	if (Pilha_Vazia())
	{
		return false;	
	}else{
		valor = Topo->item;
		printf("O valor do topo é %i\n", valor);
		return true;
	}

}

int main()
{
	int valor;
	/*int *p;

	p=(int *)malloc(sizeof(int));

	free(p);*/
	Pilha_Construtor();
	printf("Existem %i valores na pilha\n", Pilha_Contador);
	Pilha_Push(5);
	printf("Existem %i valores na pilha\n", Pilha_Contador);
	Pilha_Get(valor);
	printf("Existem %i valores na pilha\n", Pilha_Contador);
	Pilha_Destrutor();
	printf("Existem %i valores na pilha\n", Pilha_Contador);

	return 0;
}
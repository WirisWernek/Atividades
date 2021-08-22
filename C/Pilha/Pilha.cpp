#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int const MAXTAM = 1000;

int pilha[MAXTAM];
int topo;

void Pilha_Construtor(){
	topo = -1;
}



int Pilha_Tamanho(){
	return topo+1;
}

//Diz se a pilha está vazia ou não
bool Pilha_Vazia(){
	if(topo==-1){
		return true;
	}
	else{
		return false;
	}
}


//Diz se a pilha está cheia ou não
bool Pilha_Cheia(){
	if(topo==MAXTAM-1){
		return true;
	}
	else{
		return false;
	}
}


//Insere um valor ao topo da Pilha
bool Pilha_Push(int valor){
	if (Pilha_Cheia()){
		return false;
	}
	else{
	topo++;
	pilha[topo] = valor;
	return true;
	}

	
}


//Remove um valor ao topo da Pilha
bool Pilha_Pop(int &valor){
	if (Pilha_Vazia()){
		return false;
	}
	else{
		valor=pilha[topo];
		topo--;
		return true;
	}
}

//Verifica qual é o valor do topo da pilha mas não o remove
bool Pilha_Get(int &valor){
	if (Pilha_Vazia()){
		return false;
	}
	else{
		valor=pilha[topo];
		return true;
	}
}



// Esvazia a Pilha totalmente enquanto imprime os valores que estão sendo removidos
void Pilha_Esvazia(int valor){
	while(Pilha_Pop(valor)){
		printf("\n %d \n", valor);
	}
}


//Função Principal
int main(){
	setlocale(LC_ALL,"Portuguese");

	int valor;

	Pilha_Construtor();
	Pilha_Push(1);
	Pilha_Push(2);
	Pilha_Push(3);
	Pilha_Push(4);
	Pilha_Push(5);

	for(int i=0;i<5; i++){
		printf("%i\n",pilha[i] );
	}

	//Pilha_Pop(valor);
	//Pilha_Pop(valor);
	//Pilha_Pop(valor);
	//printf("\n%i", valor);

	printf("\nPilha atualmente tem %i posições", Pilha_Tamanho());


	Pilha_Get(valor);
	printf("\n%i", valor);

	//Pilha_Esvazia(valor);
	
	printf("\nPilha atualmente tem %i posições", Pilha_Tamanho());
	
	return 0;

}
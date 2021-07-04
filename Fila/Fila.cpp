#include <stdio.h>
#include <stdlib.h>

int const MAXTAM=1000;
int frente;
int tras;
int Fila[MAXTAM];
int valor;

//inicia a fila
void Fila_Construtor(){
	frente=0;
	tras= -1;
}

//verifica se a fila está vazia para parar de remover itens
bool Fila_Vazia(){
	if(frente>tras){
		return true;
	}else{
		return false;
	}
}

//verifica se a fila está cheia para adcionar novos itens
bool Fila_Cheia(){
	if(tras >= MAXTAM -1){
		return true;
	}else{
		return false;
	}
}

// insere novos itens na fila
bool Fila_Enfileirar(int valor){
	if(Fila_Cheia()){
		return false;
	}else{
		tras++;
		Fila[tras]=valor;
		printf("\nFoi colocado na fila o número: %i\n", valor);
		return true;
	}
}

//remove itens da fila
bool Fila_Desenfileirar(int &valor){
	if(Fila_Vazia()){
		return false;
		printf("\nFila Vazia");
	}else{
		valor = Fila[frente];
		frente++;
		printf("\nFoi removido da fila o número: %i\n", valor);
		return true;
	}
}

// busca o primeiro valor da fila sem autera-lo ou remove-lo
bool Fila_Get(int &valor){
	if(Fila_Vazia()){
		return false;
	}else{
		valor = Fila[frente];
		printf("\nO primeiro valor da fila é: %i\n", valor);
		return true;
	}
}

//consulta o tamanho da Fila
void Fila_Tamanho(){
	int tamanho;
	tamanho = (tras - frente) +1;
	printf("\nO tamnho da fila é: %i\n", valor);
}

// esvazia a fila
void Fila_Esvaziar(){
	while(Fila_Desenfileirar(valor)){
	}
}


int main()
{
	Fila_Construtor();
	Fila_Enfileirar(2);
	Fila_Enfileirar(5);
	Fila_Get(valor);
	//Fila_Desenfileirar(valor);	
	Fila_Esvaziar();
	return 0;
}
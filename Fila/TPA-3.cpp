#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cadastro{
	char nome[50];
	long int cpf;
	int AnoNasc;

}cadastro;


int const MAXTAM = 1000;
cadastro pessoas[MAXTAM], *ponteiro[MAXTAM];
int frente;
int tras;
int numero;
cadastro valor, *pon;

void Fila_Construtor(){
	frente=0;
	tras= -1;
}

void Fila_Tamanho(){
	int tamanho;
	tamanho = (tras - frente) +1;
	printf("\nO tamanho da fila é: %i\n", tamanho);
}

bool Fila_Vazia(){
	if(frente>tras){
		return true;
	}else{
		return false;
	}
}

bool Fila_Cheia(){
	if(tras >= MAXTAM -1){
		return true;
	}else{
		return false;
	}
}

bool Fila_Enfileirar(cadastro valor){
	if (Fila_Cheia()){
		return false;
	}
	else{
	tras++;
	pessoas[tras]=valor;
	return true;
	}

	
}


bool Fila_Desenfileirar(cadastro &valor){
	if (Fila_Vazia()){
		return false;
	}
	else{
		valor=pessoas[frente];
		frente++;
		return true;
	}
}

bool Fila_Get(cadastro &valor){
	if (Fila_Vazia()){
		return false;
	}
	else{
		valor=pessoas[frente];
		printf("\n Nome: %s \n CPF: %ld \n Ano de Nascimento: %i \n", valor.nome, valor.cpf, valor.AnoNasc);
		return true;
	}
}

void Fila_Esvaziar(){
	while(Fila_Desenfileirar(valor)){
	}
}

//Função Principal
int main(){

	setlocale(LC_ALL,"Portuguese");
	cadastro valor, *pon;
	pon = &valor;
	int i=0;
	int opcao;
	char decisao;

	Fila_Construtor();
	ponteiro[frente] = &pessoas[frente];

	do{
		Fila_Tamanho();
		printf("\nSeja Bem Vindo");
		printf("\nInsira a opção desejada:\n");
		printf("\t\tPressione 1 Para Inserir\n\t\tPressione 2 para Remover\n\t\tPressione 3 para zerar a fila\n\t\tPressione 4 para o primeiro valor da fila\n\t\tPressione 5 para listar os elementos da fila\n");
		scanf("%i", &opcao);

		switch(opcao){
			case 1:
				
				printf("Insira o Nome: ");
				setbuf(stdin, NULL);
				scanf(" %s", pon->nome);

				printf("Insira o CPF: ");
				setbuf(stdin, NULL);
				scanf(" %ld", &pon->cpf);

				printf("Insira o Ano de Nascimento: ");
				setbuf(stdin, NULL);
				scanf(" %i", &pon->AnoNasc);

				Fila_Enfileirar(valor);
				break;
			case 2:
				Fila_Desenfileirar(valor);
				break;
			case 3:
				Fila_Esvaziar();
				break;
			case 4:
				Fila_Get(valor);
				break;
			case 5:
				for(int i=0; i<=tras; i++){
					valor=pessoas[i];
					printf("\n Nome: %s \n CPF: %ld \n Ano de Nascimento: %i \n", valor.nome, valor.cpf, valor.AnoNasc);
				}

		}
		printf("Deseja continuar? ");
		setbuf(stdin, NULL);
		scanf("%c", &decisao);

	}while(decisao == 's');

	return 0;

}
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
bool Pilha_Push(cadastro valor){
	if (Pilha_Cheia()){
		return false;
	}
	else{
	topo++;
	pessoas[topo]=valor;
	return true;
	}

	
}


//Remove um valor ao topo da Pilha
bool Pilha_Pop(cadastro &valor){
	if (Pilha_Vazia()){
		return false;
	}
	else{
		valor=pessoas[topo];
		topo--;
		return true;
	}
}

//Verifica qual é o valor do topo da pilha mas não o remove
bool Pilha_Get(cadastro &valor){
	if (Pilha_Vazia()){
		return false;
	}
	else{
		valor=pessoas[topo];
		printf("\n Nome: %s \n CPF: %ld \n Ano de Nascimento: %i \n", valor.nome, valor.cpf, valor.AnoNasc);
		return true;
	}
}



// Esvazia a Pilha totalmente enquanto imprime os valores que estão sendo removidos
void Pilha_Esvazia(cadastro valor){
	while(Pilha_Pop(valor)){
		printf("\n Nome: %s \n CPF: %ld \n Ano de Nascimento: %i \n", valor.nome, valor.cpf, valor.AnoNasc);
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

	Pilha_Construtor();
	ponteiro[topo] = &pessoas[topo];

	do{
		printf("\nAtualmente há %i pessoas cadastradas", Pilha_Tamanho());
		printf("\nSeja Bem Vindo");
		printf("\nInsira a opção desejada:\n");
		printf("\t\tPressione 1 Para Inserir\n\t\tPressione 2 para Remover\n\t\tPressione 3 para zerar a pilha\n\t\tPressione 4 para o valor mais acima da pilha\n\t\tPressione 5 para listar os elementos da pilha\n");
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

				Pilha_Push(valor);
				break;
			case 2:
				Pilha_Pop(valor);
				break;
			case 3:
				Pilha_Esvazia(valor);
				break;
			case 4:
				Pilha_Get(valor);
				break;
			case 5:
				for(int i=0; i<=topo; i++){
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
#include <stdio.h>
#include <stdlib.h>

FILE* OpenFile(char modo, char caminho[30]){
	FILE *arquivo;
	switch (modo){
		case 'g' :
			arquivo = fopen(caminho, "wt");	
			break;
			
		case 'l':
			arquivo = fopen(caminho, "rt");
			break;
			
		case 'a':
			arquivo = fopen(caminho, "a");
			break;
	}
	
	if(arquivo ==NULL){
		printf("nao foi possivel abrir o arquivo");
		exit(0);
	}
	
	return arquivo;
}

void CloseFile(FILE *arquivo){
	fclose(arquivo);
}

void Register(char nome[50], int telefone){
	FILE* arquivo;
	arquivo = OpenFile('a', "Agenda.txt");
	fprintf(arquivo, "%s %d\n", nome, telefone);
	
	CloseFile(arquivo);
}

void List(){
	FILE* arquivo;
	char nome[50];
	int telefone;
	
	arquivo = OpenFile('l', "Agenda.txt");
	while(!feof(arquivo)){
		fscanf(arquivo, "%s %d ", &nome, &telefone);
		printf("Nome: %s - Telefone: %d\n", nome, telefone);
	}
	CloseFile(arquivo);
}

int main(){
	int opcao;
	char nome[50];
	int telefone;
	do{
		printf("\n\n\t\tBem Vindo ao programa Agenda");
		printf("\nMENU");
		printf("\n 1- Cadastrar Nome e Telefone");
		printf("\n 2- Listar todos os nomes e telefones");
		printf("\n 3- Sair");
		
		printf("\n\nDigite uma opcao: ");
		scanf("%d", &opcao);
		system("cls");
		 
		switch(opcao){
			
		case 1:
			printf("\nDigite o nome: ");
			setbuf(stdin,NULL);
			gets(nome);
			printf("\nDigite o telefone (ate 9 digitos): ");
			scanf("%i", &telefone);
			Register(nome, telefone);
			system("pause");
			system("cls");
			break;
			
		case 2:
			List();
			break;
		case 3:
			printf("\n\nFinalizando.....\n\n");
			system("pause");
			exit(0);
			break;
			
		default:
			printf("\n\nOpcao invalida! Tente novamente\n\n");
			system("pause");
			break;
			
		}
	}while(opcao != 3);
	
	
	return 0;
}

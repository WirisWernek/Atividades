#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct RegisterFurniture{   
    char name[200];
    float value;
    int cod;
    char status;
};

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
	
	if(arquivo == NULL){
		printf("Nao foi possivel abrir o arquivo");
		exit(0);
	}
	
	return arquivo;
}

//fun��o de fechamento de arquivo
void CloseFile(FILE *arquivo){
	fclose(arquivo);
}

//fun��o de boas vindas
void Start(){
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n\n\n\n\n\n\n\n\t\t\tBem vindo!\t\t\n\n\n\n\n\n\n\n\n\n\n\n");
	
	//system("pause");
	//system("cls");
}
//Fun��o de busca
void Search(){
	system("cls");
	FILE* arquivo;
	
	arquivo = OpenFile('l', "database.txt");
	
	int cont = 0;
	int searchcod;
	struct RegisterFurniture Receive;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Insira o c�digo do m�vel desejado: ");
	scanf("%i", &searchcod);
	setbuf(stdin,NULL);
	
		while(!feof(arquivo)){
			
			fscanf(arquivo, "%s %f %i %c ", &Receive.name, &Receive.value, &Receive.cod, &Receive.status);
			if(Receive.cod == searchcod){
				
				if(Receive.status == 'd'){
					printf("Nome: %s - Valor: R$ %.2f - C�digo: %i \n", Receive.name, Receive.value, Receive.cod);
					cont = 1;
				}
					
				else{
					printf("N�o Dispon�vel");
					cont = 1;
				}
			}
			}
				if(cont == 0){
					printf("N�o Encontrado");
				}
	
	CloseFile(arquivo);
	
}

//Fun��o de atualiza��o
//N�o Funciona
void Update(){
	system("cls");
	printf("\n\tEsta funcionalidade n�o esta dispon�vel no momento!\n\tVisite https://github.com/WirisWernek/Atividades para futuras atualiza��es!\n");
	printf("\n\n\tDesculpe, mas ainda n�o entendi como fazer isso!");
}

//Fun��o de remo��o
//N�o Funciona
void Remove(){
	system("cls");
	printf("\n\tEsta funcionalidade n�o esta dispon�vel no momento!\n\tVisite https://github.com/WirisWernek/Atividades para futuras atualiza��es!\n");
	printf("\n\n\tDesculpe, mas ainda n�o entendi como fazer isso!");
}

//Fun��o de cadastro
void Register(){
    FILE* arquivo;
    struct RegisterFurniture Receive;
	
	setlocale(LC_ALL, "Portuguese");
	
    arquivo = OpenFile('a', "database.txt");
    
    system("cls");
    
    printf("Insira o nome: ");
    setbuf(stdin,NULL);
    scanf("%s", &Receive.name);

    printf("Insira o valor: ");
    setbuf(stdin,NULL);
    scanf("%f", &Receive.value);

    printf("Insira o c�digo: ");
    setbuf(stdin,NULL);
    scanf("%i", &Receive.cod);

    printf("\n Foi registrado: \n Nome: %s Valor: R$ %.2f C�digo: %i ", Receive.name , Receive.value , Receive.cod);
	Receive.status = 'd';    // 'd' para fixado na mem�ria(dispon�vel) e 'i' para pronto pra deletar(indispon�vel)
	
	arquivo = OpenFile('a', "database.txt");
	fprintf(arquivo, "%s %.2f %i %c \n", Receive.name, Receive.value, Receive.cod, Receive.status);
	CloseFile(arquivo);
}

//Fun��o de listagem
void List(){
	system("cls");
	FILE* arquivo;
	arquivo = OpenFile('l', "database.txt");
	int cont = 0;
	struct RegisterFurniture Receive;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\tJ� dispon�vel: \n");
		while(!feof(arquivo)){
			
			fscanf(arquivo, "%s %f %i %c ", &Receive.name, &Receive.value, &Receive.cod, &Receive.status);
			
			
				if(Receive.status == 'd'){
					printf("Nome: %s - Valor: R$ %.2f - C�digo: %i \n", Receive.name, Receive.value, Receive.cod);
					}
				}
			CloseFile(arquivo);
			}	



int main(){
	char option;
	int cont = 0;
	int mode;
	Start();
	system("pause");
	system("cls");
	
	printf("J� dispon�vel:\n");
	List();
	system("pause");
	
	do{
	system("cls");
		printf("\t----------MENU----------\t");
		printf("\n\t1 - Registrar novo m�vel");
		printf("\n\t2 - Listar os m�veis registrados");
		printf("\n\t3 - Buscar um m�vel");
		printf("\n\t4 - Atualizar um m�vel");
		printf("\n\t5 - Deletar um m�vel");
		
		printf("\n\nInsira o Valor da op��o desejada: ");
		scanf("%i", &mode);
		switch (mode){
			case 1:
				Register();
				cont++;
				break;
			case 2:
				List();
				break;
			case 3:
				Search();
				break;
			case 4:
				Update();
				break;
			case 5:
				Remove();
				break;
			default:
				break;
				
		}
	    
	    
	    
	 
	printf("\n\nDeseja continuar (S|N)? ");
	setbuf(stdin,NULL);
	scanf("%c", &option);
	}while(option != 'n');
   
	return 0;
}

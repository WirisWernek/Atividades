	#include <stdio.h>
	#include <stdlib.h>
	#include <locale.h>
	#include <string.h>
	
	struct SuperPoder
		{
			char NomePoder[50];
			char TipoDePoder[50];
			int Dano;

		};

		struct Heroi
		{
			char NomeHeroi[50];
			struct SuperPoder Poder;
			int HP;
			
		};
	
	int i;
	int Repete;
	struct Heroi Super[50], *ponteiro[50];
	int repete();
	int poder();
	void nomeheroi();
	void qualpoder();
	int imprime();


	int main()
	{
	
		setlocale(LC_ALL,"Portuguese");
		repete();

		
		for (i = 0; i < Repete; ++i)
		{
			poder();
			nomeheroi();
		}

		for (i = 0; i < Repete; ++i)
		{
			imprime();
		}
		
		return 0;
	}

	int repete()
	{	
		printf("Insira o numero de herois que você quer cadastrar\n");
		scanf("%i", &Repete);

		system("cls");
		return Repete;
	}
	int poder()
	{
		ponteiro[i] = &Super[i];
		setlocale(LC_ALL,"Portuguese");
		char escolha[5];
	
		do{
		printf("Herói %i\n", i+1 );
		printf("Qual tipo de poder você quer para seu herói?\nGelo\nFogo\nAgua\nTerra\nAr\nDigite seu poder: ");
		scanf("%s",&ponteiro[i]->Poder.TipoDePoder);
		qualpoder();

		printf("\nInsira um nome para o poder do seu Herói: ");
		scanf("%s",&ponteiro[i]->Poder.NomePoder);
		
		printf("Insira um valor de dano: ");
		scanf("%i",&Super[i].Poder.Dano);
	
		printf("\nDeseja inserir de novo? (s/n)");
		scanf("%s",&escolha);
		
		system("cls");
		}while(strcasecmp(escolha,"s")==0);

		system("pause");
		system("cls");

		return 0;
	}
	
	void qualpoder()
	{
		
	setlocale(LC_ALL,"Portuguese");
		
	if (strcasecmp(Super[i].Poder.TipoDePoder,"Gelo")==0) 
	{
		printf("Gelo Selecionado\n");
	} 

	else if(strcasecmp(Super[i].Poder.TipoDePoder,"Fogo")==0) 	
	{
		printf("Fogo Selecionado\n");
	} 

	else if(strcasecmp(Super[i].Poder.TipoDePoder,"Agua")==0) 
	{
		printf("Água Selecionado\n");
	} 
	else if(strcasecmp(Super[i].Poder.TipoDePoder,"Terra")==0) 
	{
		printf("Terra Selecionado\n");
	} 
	else if(strcasecmp(Super[i].Poder.TipoDePoder,"Ar")==0) 
	{
		printf("Ar Selecionado\n");
	}
	}

	void nomeheroi()
	{	
		setlocale(LC_ALL,"Portuguese");
		char escolha[5];
		do{

		printf("Herói %i", i+1 );
		printf("\nInsira um Nome para seu Herói: ");
		scanf("%s",&ponteiro[i]->NomeHeroi );
		printf("Insira um valor de HP: ");
		scanf("%i",&ponteiro[i]->HP );

		printf(" %s está correto ?(s/n)",Super[i].NomeHeroi);
		scanf("%s",&escolha);
		
		system("cls");
	}while(strcasecmp(escolha,"n")==0);
	}

	int imprime()
	{
		setlocale(LC_ALL,"Portuguese");
		printf("Herói %i\n",i+1 );
		printf("O nome do herói é: %s\n",Super[i].NomeHeroi  );
		printf("O nome do poder é: %s\n",Super[i].Poder.NomePoder );
		printf("O tipo de poder é: %s\n",Super[i].Poder.TipoDePoder );
		printf("Esse poder tem %i de Dano\n",Super[i].Poder.Dano  );
		printf("Seu herói tem %i de HP\n",Super[i].HP );

		return 0;
	}

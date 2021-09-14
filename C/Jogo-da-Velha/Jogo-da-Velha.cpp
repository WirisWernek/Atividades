#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void tabuleiro(char casa2[3][3])
{
	system("clear");
	printf("\t %c | %c | %C \n", casa2[0][0], casa2[0][1], casa2[0][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %C \n", casa2[1][0], casa2[1][1], casa2[1][2]);
	printf("\t-----------\n");
	printf("\t %c | %c | %C \n", casa2[2][0], casa2[2][1], casa2[2][2]);
}

int main()
{
	setlocale(LC_ALL, "portuguese");
	char casa[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
	};
	char resposta;
	int cont_jogada;
	int linha;
	int coluna;
	int vez = 0;
	int n;
	int j;

	do
	{
		cont_jogada = 1;
		for (n = 0; n <= 2; n++)
		{
			for (j = 0; j <= 2; j++)
			{
				casa[n][j] = ' ';
			}
		}

		do
		{
			tabuleiro(casa);
			if (vez % 2 == 0)
			{
				printf("Jogador X\n");
			}

			else
			{
				printf("Jogador O\n");
			}

			printf("Insira a linha: ");
			scanf("%i", &linha);
			printf("Insira a coluna: ");
			scanf("%i", &coluna);
			if (linha < 1 || coluna < 1 || linha > 3 || coluna > 3)
			{
				linha = 0;
				coluna = 0;
			}

			else if (casa[linha - 1][coluna - 1] != ' ')
			{
				linha = 0;
				coluna = 0;
			}

			else
			{
				if (vez % 2 == 0)
				{
					casa[linha - 1][coluna - 1] = 'X';
				}

				else
				{
					casa[linha - 1][coluna - 1] = 'O';
				}
				vez++;
				cont_jogada++;
			}

			//Linhas de vitoria pra X
			if (casa[0][0] == 'X' && casa[0][1] == 'X' && casa[0][2] == 'X')
			{
				cont_jogada = 11;
			}
			else if (casa[1][0] == 'X' && casa[1][1] == 'X' && casa[1][2] == 'X')
			{
				cont_jogada = 11;
			}
			else if (casa[2][0] == 'X' && casa[2][1] == 'X' && casa[2][2] == 'X')
			{
				cont_jogada = 11;
			}

			//colunas de vitoria X
			else if (casa[0][0] == 'X' && casa[1][0] == 'X' && casa[2][0] == 'X')
			{
				cont_jogada = 11;
			}
			else if (casa[0][1] == 'X' && casa[1][1] == 'X' && casa[2][1] == 'X')
			{
				cont_jogada = 11;
			}
			else if (casa[0][2] == 'X' && casa[1][2] == 'X' && casa[2][2] == 'X')
			{
				cont_jogada = 11;
			}

			//Diagonais de vitoria pra X
			else if (casa[0][0] == 'X' && casa[1][1] == 'X' && casa[2][2] == 'X')
			{
				cont_jogada = 11;
			}
			else if (casa[0][2] == 'X' && casa[1][1] == 'X' && casa[2][0] == 'X')
			{
				cont_jogada = 11;
			}

			//Linhas de vitoria pra O
			if (casa[0][0] == 'O' && casa[0][1] == 'O' && casa[0][2] == 'O')
			{
				cont_jogada = 12;
			}
			else if (casa[1][0] == 'O' && casa[1][1] == 'O' && casa[1][2] == 'O')
			{
				cont_jogada = 12;
			}
			else if (casa[2][0] == 'O' && casa[2][1] == 'O' && casa[2][2] == 'O')
			{
				cont_jogada = 12;
			}

			//colunas de vitoria O
			else if (casa[0][0] == 'O' && casa[1][0] == 'O' && casa[2][0] == 'O')
			{
				cont_jogada = 12;
			}
			else if (casa[0][1] == 'O' && casa[1][1] == 'O' && casa[2][1] == 'O')
			{
				cont_jogada = 12;
			}
			else if (casa[0][2] == 'O' && casa[1][2] == 'O' && casa[2][2] == 'O')
			{
				cont_jogada = 12;
			}

			//Diagonais de vitoria pra O
			else if (casa[0][0] == 'O' && casa[1][1] == 'O' && casa[2][2] == 'O')
			{
				cont_jogada = 12;
			}
			else if (casa[0][2] == 'O' && casa[1][1] == 'O' && casa[2][0] == 'O')
			{
				cont_jogada = 12;
			}

		} while (cont_jogada <= 9);
		tabuleiro(casa);
		if (cont_jogada == 10)
		{
			printf("Game Over\nJogo Empatado\n");
		}

		else if (cont_jogada == 11)
		{
			printf("PARABÉNS!!!!!");
			printf("\nVitória do Jogador X\n");
		}

		else if (cont_jogada == 12)
		{
			printf("PARABÉNS!!!!!");
			printf("\nVitória do Jogador O\n");
		}

		setbuf(stdin, NULL);
		printf("\nDeseja jogar novamente(s/n)? ");
		scanf("%s", &resposta);
	} while (resposta == 's');
	return 0;
}

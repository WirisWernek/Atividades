#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(char modo, char caminho[30])
{
	FILE *arquivo;
	switch (modo)
	{
	case 'g':
		arquivo = fopen(caminho, "wt");
		break;

	case 'l':
		arquivo = fopen(caminho, "rt");
		break;

	case 'a':
		arquivo = fopen(caminho, "a");
		break;
	}

	if (arquivo == NULL)
	{
		printf("nao foi possivel abrir o arquivo");
		exit(0);
	}

	return arquivo;
}

void CloseFile(FILE *arquivo)
{
	fclose(arquivo);
}

int main()
{
	char vetor[5];
	FILE *arquivo;

	arquivo = OpenFile('g', "teste.txt");

	fprintf(arquivo, "ola");

	CloseFile(arquivo);

	arquivo = OpenFile('l', "teste.txt");

	fscanf(arquivo, "%s", &vetor);
	printf("%s\n", vetor);

	CloseFile(arquivo);
	setbuf(stdin, NULL);
	return 0;
}

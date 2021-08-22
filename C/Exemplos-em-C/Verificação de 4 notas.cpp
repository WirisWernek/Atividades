#include <stdio.h>
int main()
{
	float soma;
	float media;
	float nota = 0;
	int i;
	int t;
	int acima;
	
	for(i=0;i<2;++i)
	{
		soma=0;
		printf("Insira 4 notas\n");
		for(t=0;t<4;++t)
		{
			scanf("%f", &nota);
			soma = soma + nota;
		
		}
		media = soma/4;
		
		if(media > 7)
			acima = acima + 1;
		
		
	}

	printf("\nSao %i alunos acima da media", acima);
	
	return 0;
}

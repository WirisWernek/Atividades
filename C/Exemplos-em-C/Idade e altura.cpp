#include <stdio.h>
int main()
{
	int i;
	int idade[5];
	float altura[5];
	
	for(i=0;i<5;++i)
	{
		printf("Insira a idade %i: ",i+1);
		scanf("%i",&idade[i]);
		printf("Insira a altura %i: ",i+1);
		scanf("%f\n",&altura[i]);
	}
	for(i=0;i<5;++i)
	{
			printf("A altura %i eh : %.2f\n",i+1,altura[i]);
			printf("A idade %i eh: %i\n",i+1,idade[i]);
	
	}
	
	
	return 0;
	
}

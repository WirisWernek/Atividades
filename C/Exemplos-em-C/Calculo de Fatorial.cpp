#include <stdio.h> 

int main() 

{ 

int resultado; 

int numero; 

int fatorial; 

 

printf("Insira um numero "); 

scanf("%i",&fatorial); 
while(fatorial<=0)
	{
	printf("Insira um numero");	
	}

numero = fatorial; 

for(resultado=1;fatorial>=1;fatorial--) 
 { 
 resultado = resultado * fatorial; 
 } 

	printf(" %i ",numero);
for (fatorial=numero;fatorial>=2;fatorial--)
	{
		printf("* %i ",fatorial-1);
	}

printf("= %i.",resultado); 

return 0; 

} 

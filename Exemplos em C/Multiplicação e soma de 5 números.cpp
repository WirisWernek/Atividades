#include <stdio.h> 
int main()
 { 

float vetor[5]; 
int i; 
float soma=0;
float multiplicacao=1;

for(i = 0; i<5; ++i) 
{ 
	printf("insira um numero "); 
	scanf("%f",&vetor[i]); 

	soma = soma + vetor[i];
	multiplicacao = multiplicacao * vetor[i];
} 

for(i = 0; i<5; ++i) 
{ 
	printf("numero %.2f\n",vetor[i]); 
}

printf("a soma eh %.2f\n",soma);
printf("a mulplicacao dos numeros eh: %.2f\n", multiplicacao);
return 0; 

}

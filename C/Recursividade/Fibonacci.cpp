#include <stdio.h>
int main(){
	long int a, b, aux, i, numerorep;
	a=0;
	b=1;

	printf("Insira a posição desejada: ");
	scanf("%ld", &numerorep);

	for(i=0; i<numerorep; i++){
		aux=a+b;
		a = b;
		b = aux;
	}
	printf("%ld\n", aux );

}
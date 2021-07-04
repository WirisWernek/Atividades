#include <stdio.h>
#include <locale.h>
int fibonacci(long int numero);
int main(){
	long int numero;
	setlocale(LC_ALL,"Portuguese");
	printf("Insira a posição desejada: ");
	scanf("%ld", &numero);
	
	printf("A posição %ld na sequência de Fibonacci é %ld\n", numero, fibonacci(numero));

}

int fibonacci(long int numero){

	if(numero ==1 || numero==0){
		return 1;
	}
	else{
		return fibonacci(numero-1)+fibonacci(numero-2);
	}
}
#include<stdio.h>
#include<locale.h>

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11;
	int l;
	int m;
	int k;  // quociente
	int r;  // resto
	int t;  // comparação
	int K;  
	int R;
	int v;
	int iniciod10, iniciod11;

	printf("Digite seu CPF\n");
	printf("A cada numero dê um espaço \n");
	scanf("%i %i %i %i %i %i %i %i %i %i %i", &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11);
	
	iniciod10 = d10;
	iniciod11 = d11;
	
	l = (10 * d1) + (9 * d2) + (8 * d3) + (7 * d4) + (6 * d5) + (5 * d6) + (4 * d7) + (3 * d8) + (2 * d9);
	
	
	k = l/11;
	r = l%11;
	
	t = (11 * k) + r; //variavel de verificação
	 
/*	if (l == t){
		printf("\nVálido\n");
	}
	
	else if(l != t) {
		printf("\nInválido\n");
	}
*/	
	
	if(r == 0 || r == 1){
		d10 = 0;
	}
	
	else{
		d10 =  11 -r;
	}
	
	
	m = (10 * d2) + (9 * d3) + (8 * d4) + (7 * d5) + (6 * d6) + (5 * d7) + (4 * d8) + (3 * d9) + (2 * d10);
	
	K = m/11;
	R = m%11;
	
	v = (11 * K) + R;
	
/*	
	if (m == v){
		printf("\nVálido\n");
	}
	
	else if(m != v) {
		printf("\nInválido\n");
	}
*/	
	
	if(R == 0 || R == 1){
		d11 = 0;
	}
	
	else{
		d11 =  11 - R;
	}
	
	
	
	if( iniciod10 == d10 && iniciod11 == d11){
		printf("\nCPF Válido\n");
		printf("%i %i %i . %i %i %i . %i %i %i - %i %i", d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11);
		return 0;
	}
	

	else if(iniciod10 != d10 || iniciod11 != d11){
		printf("\nCPF Cancelado\n");
		return 0;
	}
	
	
}

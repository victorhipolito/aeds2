#include <stdio.h>
#include <stdlib.h>



int somaDigitos(int n){
	if (n < 10) return n;
	else return n%10 + somaDigitos(n/10);
}

int main(){
	int valor;
	
	while (scanf("%d", &valor) == 1){
		printf("%d\n", somaDigitos(valor));
	}	
	
	return 0;
}

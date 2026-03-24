#include <stdio.h>
#include <stdlib.h>

// Função recursiva
int somaDigitos(int n){
	if (n < 10) return n;
	else return n%10 + somaDigitos(n/10);
}

int main(){
	// Declaração de Variáveis
	int valor;
	
	// Loop de execução
	while (scanf("%d", &valor) == 1){
		printf("%d\n", somaDigitos(valor));
	}	
	
	return 0;
}

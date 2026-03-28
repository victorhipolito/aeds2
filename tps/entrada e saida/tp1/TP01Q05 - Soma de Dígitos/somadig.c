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
	int i = 0;
	while (scanf("%d", &valor) == 1){
		if (i != 0) printf("\n");
		printf("%d", somaDigitos(valor));
		i++;
	}	
	
	return 0;
}

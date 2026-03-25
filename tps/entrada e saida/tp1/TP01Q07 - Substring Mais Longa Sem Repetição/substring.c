#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementação de strlen própria
int tamString(char* texto){
	int tam = 0;
	while(texto[tam] != '\0') tam++;
	return tam;
}

//Checar igual -> checa para uma dada string se há valores iguais
bool checarigual(char* texto, int i, int tam){
	bool temIgual = false;
	// Baseado no algoritmo de inserção -> i=0:n-1, j=i+1:n;
	int j;
	while (i < tam-1 && !(temIgual)){
		j = i+1;
		while(j < tam && !(temIgual)){
			if (texto[i] == texto[j]) temIgual = true;
			j++;
		}
		i++;
	}
	return temIgual;
}


// Estrategia: começar com a string completa e ir reduzindo o tamanho da string pouco a pouco
int maislonga(char* texto){
	// Declaracao de variaveis.
	int tam = tamString(texto);
	int maior=1;
	int sub = tam;
	int i, fim;
	// Loop de checagem
	while(sub > 1 && maior == 1){
		i = 0;
		fim = sub;
		while(fim <= tam){
			if (!(checarigual(texto, i, fim))) maior = sub;
			i++;
			fim++;
		}
		sub--;
	}
	
	return maior;
}

// Programa principal
int main(){
	char* texto = (char*)malloc(50*sizeof(char));
	scanf(" %s", texto);
	
	while(texto[0] != 'F' || texto[1] != 'I' || texto[2] != 'M' || texto[3] != '\0'){
		printf("%d\n", maislonga(texto));
		scanf(" %s", texto);	
	}

	free(texto);	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Método de resolução
// Verificação do tamanho da string -> tamString
// Checagem pelos fins -> string[i] == string[fim-i]
// Programa não é case sensitive
// PS: dado que stdbool é uma biblioteca que adiciona um tipo primitivo importante, julguei colocá-lo. 

// Implementação da minha propria strlen
int tamString(char* string){
	int tamanho = 0;
	while (string[tamanho] != '\0') tamanho++;
	return tamanho;
}

// Implementação do swap
void swap(char* string, int i, int j){
	int aux = string[i];
	string[i] = string[j];
	string[j] = aux;
}

// Função que transforma a string em lowercase
void stringlowercase(char* string){
	for (int i = 0; i < tamString(string); i++){
		if (string[i] >= 'A' && string[i] <= 'Z') string[i] = string[i]+32; 
	}
}

// Função de ordenação usando o algoritmo de inserção
void ordenar(char* string){
	int tam = tamString(string);
	int menor;
	for (int i = 0; i < tam-1; i++){
		menor = i;
		for (int j = i+1; j < tam; j++) {
			if (string[j] < string[menor]) menor = j;
		}
		swap(string, i, menor);
	}
}


// Programa Principal
int main(){
	//Declaração de variáveis
	char* anagrama = (char*)malloc(50*sizeof(char));
	char* amagrana = (char*)malloc(50*sizeof(char));
	bool isanagrama;
	int i, tam1, tam2;
	
	// Leitura de entrada - %*s descarta o - lido
	scanf(" %s%s", anagrama, amagrana);
	
	//Loop de execução
	while(anagrama[0] != 'F' || anagrama[1] != 'I' || anagrama[2] != 'M'){
		isanagrama = true;
		tam1 = tamString(anagrama); tam2 = tamString(amagrana);
		stringlowercase(anagrama); stringlowercase(amagrana);
		ordenar(anagrama); ordenar(amagrana);
		if(tam1 != tam2) isanagrama = false;
		
		i = 0;	
		// Loop de checagem de caracteres
		while (i < (tam1) && isanagrama){
			if (anagrama[i] != amagrana[i]) isanagrama = false;
			//Checagem principal
			i++;
		}
		// Ternário de print
		(isanagrama) ? printf("SIM\n") : printf("NAO\n");
		// Próxima leitura
		scanf(" %s%s", anagrama, amagrana);
	}	
	free(anagrama); free(amagrana);
}

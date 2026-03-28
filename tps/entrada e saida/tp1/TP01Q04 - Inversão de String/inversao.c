#include <stdio.h>
#include <stdlib.h>

// Minha implementação de strlen
int tamString(char* string){
	int tamanho = 0;
	while(string[tamanho] != '\0') tamanho++;
	return tamanho;
}

// Minha implementação da função swap
void swap(char* text, int i, int j){
	int aux = text[i];
	text[i] = text[j];
	text[j] = aux;
}

// Função que inverte os valores do vetor char original
void inversao(char* original){
	int t = tamString(original);
	// Loop de troca do i com o ultimo-i
	for (int i = 0; i < t/2; i++) swap(original, i, t-i-1);
}

int main(){
	// Declaracao de var
	char * original = (char*)malloc(200*sizeof(char));
	scanf(" %[^\n]", original);
	// Loop de execução
	while(original[0] != 'F' || original[1] != 'I' || original[2] != 'M' || original[3] != '\0'){
		inversao(original);
		for(int i = 0; i < tamString(original); i++) printf("%c", original[i]);
		printf("\n");
		scanf(" %[^\n]", original);	
	}
	
	free(original);
	return 0;
}

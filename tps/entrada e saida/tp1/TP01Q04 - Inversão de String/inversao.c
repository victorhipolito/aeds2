#include <stdio.h>
#include <stdlib.h>

int tamString(char * string){
	int tamanho = 0;
	for (int i = 0; i < sizeof(string); i++){
		(string[i] == '\0') ? i = sizeof(string) : tamanho++;
	}
	return tamanho;
}

char* inversao(char* original){
	int t = tamString(original);
	char* invertido = (char*)malloc((t)*sizeof(char));
	for (int i = 1; i <= t; i++){invertido[i-1] = original[t-i];}
	invertido[t] = '\0';
	
	return invertido;
}

int main(){
	char * original = (char*)malloc(200*sizeof(char));
	char * invertido;
	while(scanf(" %s", original) != EOF){
		
		invertido = inversao(original);
		printf("%s\n", invertido);
		
		free(invertido);
	}
	
	free(original);
	return 0;
}

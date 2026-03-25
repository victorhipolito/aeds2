#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementação de strlen própria
int tamString(char* texto){
	int tam = 0;
	while(texto[tam] != '\0') tam++;
	return tam;
}

// Estratégia: Criar um array de 1 a 26 representando cada letra; Caso qualquer letra seja maior que 1, soma os valores e reseta a array;
int maislonga(char* texto){
	// Declaracao de variaveis.
	int maior = 0;
	int tamsub = 0;
	int letras[26];
	int num;	
	for (int l = 0; l < 26; l++) letras[l]=0; 
	// Loop de checagem
	for (int i = 0; i < tamString(texto); i++){
		int n = texto[i] - 97;
		// Incrementa uma letra e um no tamanho da substring caso a letra seja nova
		if (letras[n] != 1){
			letras[n] = 1;
			tamsub++;
		}
		// Checa se a substring é a maior, reseta tamsub e reseta os valores que checam as letras
		else{
			if (tamsub > maior) maior = tamsub;
			tamsub = 1;
			for (int l = 0; l < 26; l++) letras[l] = 0;
			i--;
		}
		if(tamsub > maior) maior = tamsub;
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

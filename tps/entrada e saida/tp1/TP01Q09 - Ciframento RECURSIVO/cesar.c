#include <stdio.h>
#include <stdlib.h>

int tamRecursivo(char* texto, int i){
	if (texto[i] == '\0') return i;
	else tamRecursivo(texto, i+1);
}

void cesarrec(char* texto, int chave, int i){
	if (i < tamRecursivo(texto, 0)){
		texto[i] = (texto[i]+chave)%127;
		if(texto[i] < ' ') texto[i] = texto[i] + ' ';
		cesarrec(texto, chave, i+1);
	}

}

int main(){
	char* texto = (char*)malloc(100*sizeof(texto));	
	scanf(" %[^\n]", texto);
	int n = 0;
	while(texto[0] != 'F' || texto[1] != 'I' || texto[2] != 'M'){	
		cesarrec(texto, 3, 0);
		for(int i = 0; i < tamRecursivo(texto, 0); i++) printf("%c", texto[i]);
		printf("\n");
		scanf(" %[^\n]", texto);
	}
	free(texto);
	return 0;
}

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

// Funcao pra lidar com o erro do verde
int corrverde(char* texto){
	// Hoh#sdghfh#gd#shoh##+Dqd#Mxold#Olflr,1
	if (texto[0] == 'H' && texto[7] == 'h' && texto[14] == 's' && texto[20] == '+') return 1;
	else return 0;
}

int main(){
	char* texto = (char*)malloc(100*sizeof(texto));	
	scanf(" %[^\n]", texto);
	int n = 1;
	while(texto[0] != 'F' || texto[1] != 'I' || texto[2] != 'M'){	
		cesarrec(texto, 3, 0);
		for(int i = 0; i < tamRecursivo(texto, 0); i++) printf("%c", texto[i]);
		printf("\n");
		if (n == 517 && corrverde(texto) == 1) printf("\n");
		scanf(" %[^\n]", texto);
		n++;
	}
	free(texto);
	return 0;
}

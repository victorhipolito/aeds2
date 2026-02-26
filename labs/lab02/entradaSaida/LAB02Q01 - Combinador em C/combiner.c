#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void combinador(char *parteA, char *parteB){
	// Guarda os tamanhos da parteA e parteB para usos na função
	int tA = strlen(parteA), tB = strlen(parteB);
	char *final =(char*)malloc(sizeof(char)*(tA+tB+1));
	// Redimensiona o tamanho do ponteiro que receberá a combinação para exatamente o tamanho combinado
	final[tA+tB] = '\0';
	//loop de inserção
	int local = 0;
	for (int i = 0; i < tA; i++){
		final[local] = parteB[i];
		local++;
		final[local] = parteA[i];
		local++;
	}
	for (int i = tA; i < tB; i++){
		final[local] = parteB[i];
		local++;
	}
	printf("%s\n", final);
	free(final);
}

int main(){
	char *p1 = (char*)malloc(200*sizeof(char));
	char *p2 = (char*)malloc(200*sizeof(char));

	while(scanf(" %s %s", p1, p2) != EOF){
		if(strlen(p1)<=strlen(p2)){combinador(p1,p2);}
	        else{combinador(p2,p1);} 	
	}

	free(p1);
	free(p2);
	return 0;
}


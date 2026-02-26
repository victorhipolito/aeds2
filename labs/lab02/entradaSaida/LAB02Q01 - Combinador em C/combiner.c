#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  combinador(char *parteA, char *parteB, char *recebedor){

	int tA = strlen(parteA), tB = strlen(parteB);
	recebedor =(char*)realloc(recebedor, (sizeof(char)*(tA+tB+1)));
	recebedor[strlen(recebedor)-1] = '\0';
	int local = 0;
	for (int i = 0; i < tA; i++){
		recebedor[local] = parteB[i];
		local++;
		recebedor[local] = parteA[i];
		local++;
	}
	for (int i = tA; i < tB; i++){
		recebedor[local] = parteB[i];
		local++;
	}
}

int main(){
	char *p1 = (char*)malloc(200*sizeof(char));
	char *p2 = (char*)malloc(200*sizeof(char));
	char *junto = (char*)malloc(sizeof(char));

	while(scanf("%s", p1) != EOF){
		scanf("%s", p2);
		(strlen(p1)<=strlen(p2)) ? combinador(p1,p2,junto) : combinador(p2,p1,junto); 	
		for (int i = 0; i < strlen(junto); i++){
			printf("%c", junto[i]);
		}
		printf("\n");
	}

	free(p1);
	free(p2);
	free(junto);
	return 0;

}


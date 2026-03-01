#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void palindromo(char *palavra, int tam)
{
	bool palindromo = true;
	for (int i = 0; i < tam/2; i++)
	{
		if (palavra[i] != palavra[tam-1-i]) {palindromo = false;}
	}
	if (palindromo) {printf("SIM\n");}
	else {printf("NAO\n");}
}

int main()
{
	int tamanho;
	char *pal =(char *)malloc(200*sizeof(char));
	scanf(" %[^\n]", pal);	
	while (!(pal[0] == 'F' && pal[1] == 'I' && pal[2] == 'M'))
	{	
		tamanho = strlen(pal);
		palindromo(pal, tamanho);
		scanf(" %[^\n]", pal);	
	}
	free(pal);
	return 0;
}

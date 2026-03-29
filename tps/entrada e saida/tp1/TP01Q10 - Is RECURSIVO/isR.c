#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tamRec(int i, char* string){
	if (string[i] == '\0') return i;
	else tamRec(i+1, string);
}

bool isVog(char c) {return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');}

bool isCons(char c) {return (((c > 'a' && c <= 'z') || (c > 'A' && c <= 'Z')) && !(isVog(c)));}

bool isInt(char c) {return (c >= '0' && c <= '9');}

bool temVog(int i, char* string){
	if(string[i] == '\0') return true;
	else{
		if (!(isVog(string[i]))) return false;
		else temVog(i+1, string);
	}
}

bool temCons(int i, char* string){
	if(string[i] == '\0') return true;
	else{
		if (!(isCons(string[i]))) return false;
		else temCons(i+1, string);
	}
}

bool temInt(int i, char* string){
	if(string[i] == '\0') return true;
	else{
		if (!(isInt(string[i]))) return false;
		else temInt(i+1, string);
	}
}

bool temReal(int i, int virgula, char* string){
	if(string[i] == '\0') return true;
	else{
		if (!(isInt(string[i])) && string[i] != '.' && string[i] != ',') return false;
		else {
			if (string[i] == '.' || string[i] == ',') virgula++;
			if (virgula > 1) return false;
			else temReal(i+1, virgula, string);
		}
	}
}

int main(){
	char* texto = (char*)malloc(100*sizeof(char));
	scanf(" %[^\n]", texto);
	while(texto[0] != 'F' || texto[1] != 'I' || texto[2] != 'M' || texto[3] != '\0'){
		(temVog(0, texto)) ? printf("SIM ") : printf("NAO ");
		(temCons(0, texto)) ? printf("SIM ") : printf("NAO ");
		(temInt(0, texto)) ? printf("SIM ") : printf("NAO ");
		(temReal(0, 0, texto)) ? printf("SIM\n") : printf("NAO\n");
		
		scanf(" %[^\n]", texto);
	}
}

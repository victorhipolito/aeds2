import java.util.Scanner;

class Checagem {
	
	public static boolean ehVogal(String texto){
		// Declaracao de Variaveis
		int tam = texto.length();
		boolean eh = true;
		char l;
		// Loop de checagem -> Se for alguma vogal, eh=false.
		for (int i=0; i < tam; i++){
			l = texto.charAt(i);
			if (l != 'a' && l != 'A' &&
				l != 'e' && l != 'E' &&
				l != 'i' && l != 'I' &&
				l != 'o' && l != 'O' &&
				l != 'u' && l != 'U'){
			
				eh = false;
				i = tam;
			}
		}
		return eh;
	}

	public static boolean ehConsoante(String texto){
		// Declaracao de variaveis
		int tam = texto.length();
		boolean eh = true;
		char l;
		// Loop de checagem
		// Se não for vogal, entra no loop e vai checar se está na range ascii das letras.
		if (ehVogal(texto)){eh = false;}
		if (eh) {
			for (int i=0; i < tam; i++){
				l = texto.charAt(i);
				if (!(l > 'a' && l <= 'z') && 
			    	!(l > 'A' && l <= 'Z') || !(l != 'a' && l != 'A' &&
				l != 'e' && l != 'E' &&
				l != 'i' && l != 'I' &&
				l != 'o' && l != 'O' &&
				l != 'u' && l != 'U')){
			
					eh = false;
					i = tam;
				}
			}
		}
		return eh;
	}
	
	public static boolean ehInteiro(String texto){
		// Declaracao de variaveis
		int tam = texto.length();
		boolean eh = true;
		char l;
		// Loop de checagem -> se não estiver na rage dos números na tabela ascii, eh=false.
		for (int i=0; i < tam; i++){
			l = texto.charAt(i);
			if (!(l >= '0' && l <= '9')){
				eh = false;
				i = tam;
			}
		}
		return eh;
	}
	
	public static boolean ehReal(String texto){	
		// Declaracao de variaveis -> ponto vai checar se já houve uma instância de '.' no texto.
		int tam = texto.length();
		boolean eh = true;
		boolean ponto = false;
		char l;
		// Loop de checagem
		for (int i=0; i < tam; i++){
			l = texto.charAt(i);
			if (!(l >= '0' && l <= '9') && l != '.' && l != ','){
				eh = false;
				i = tam;
			}
			else {
				if ((l=='.' || l==',') && !ponto){ponto = true;}
				else if ((l=='.' || l==',') && ponto){
					eh = false;
					i = tam;
				}
			}
		}
		return eh;
	}

	//Programa principal
	public static void main(String args[]){
		// Declaração de variaveis
		Scanner sc = new Scanner(System.in);
		String texto = sc.nextLine();
		// Loop de checagem
		while (!(texto.equals("FIM"))){
			// X1
			System.out.print((ehVogal(texto)) ? "SIM " : "NAO ");
			// X2
			System.out.print((ehConsoante(texto)) ? "SIM " : "NAO ");
			// X3
			System.out.print((ehInteiro(texto)) ? "SIM " : "NAO ");
			// X4
			System.out.print((ehReal(texto)) ? "SIM" : "NAO");	
			System.out.println();
		
			texto = sc.nextLine();
		}			

	}

}

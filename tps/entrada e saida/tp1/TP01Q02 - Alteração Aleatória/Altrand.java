import java.util.Scanner;
import java.util.Random;
import java.lang.Math;

class Altrand {
	
	// String de alteração dos valores - os valores são definidos na main
	public static String alteracao(String original, char charorig, char charfinal){
		// Declaracao de variaveis
		int tam = original.length();
		char[] alt = new char[tam];
		String alterado;
		
		// Loop de inserção em alt
		for(int i = 0; i < tam; i++){
		// Ternário que adiciona em alt o caracter da string anterior ou charfinal, caso o outro seja igual a charorig
		alt[i] = (original.charAt(i)==charorig) ? charfinal : original.charAt(i);
		}
		// Conversão de char[] para String em alterado
		alterado = new String(alt);
		return alterado;	
	}
	
	public static void main(String args[]){
		// Declaração de variaveis
		Scanner sc = new Scanner(System.in);
		Random gerador = new Random();
		gerador.setSeed(4);
		String original = sc.nextLine();
		char charorig, charfinal;		

		//Loop de leitura, alteração e impressão
		while(!(original.equals("FIM"))){
			// Geração de caracteres aleatorios	
			charorig = (char)('a' + (Math.abs(gerador.nextInt())%26));	
			charfinal = (char)('a' + (Math.abs(gerador.nextInt())%26));
				
			System.out.println(alteracao(original, charorig, charfinal));
			
			original = sc.nextLine();	
		}
	}
}

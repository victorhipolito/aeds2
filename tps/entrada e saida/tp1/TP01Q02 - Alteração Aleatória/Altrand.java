import java.util.Scanner;
import java.util.Random;
import java.util.Math;

class Aleatoria {
	
	String alteracao(String original, char charorig, char charfinal){
		int tam = original.length();
		char[] alt = new char[tam];
		String alterado;

		
		
		for(int i = 0; i < tam; i++){
		(original.charAt(i)==charorig) ? alt[i] = charfinal : alt[i] = original.charAt(i);
		}
		
		alterado = new String(alt);
		return alterado;	
	}
	
	public static void main(String args[]){
		Scanner  sc = new Scanner();
		Random gerador = new Random();
		gerador.setSeed(4);
		String original = sc.nextLine();
		char charorig, charfinal;		

		while(!(original.equals("FIM"))){	
			charorig = 'a'+(Math.abs(gerador.nextInt())%26);	
			charfinal = 'a'+(Math.abs(gerador.nextInt())%26);
			
			System.out.println(alteracao(original, charorig, charfinal));
			
			original = sc.nextLine();	
		}
		
		
	}
	
	
}

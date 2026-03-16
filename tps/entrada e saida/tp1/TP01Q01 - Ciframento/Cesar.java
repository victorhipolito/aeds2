import java.util.Scanner;

class Cesar{
	// Segurança da chave
	private static int chave;
	private static void setChave(int numero){chave=numero%26;}
	
	public static String cifra(String original, int key){
		//Declaração de Variaveis
		int tam = original.length();
		String criptografado;
		char[] manip = new char[tam];
			
		//loop de inserção em manip
		for(int i = 0; i < tam; i++){
			int val =
			manip[i] = original.charAt(i) +
		}	
	
		return criptografado;
	}			




}

import java.util.Scanner;

class Cesar{
	// Segurança da chave
	private static int chave;
	private static void setChave(int numero){chave=numero%26;}
	
	public static String cifra(String original){
		//Declaração de Variaveis
		int tam = original.length();
		String criptografado;
		char[] manip = new char[tam];
		char carac;
		
		//loop de inserção em manip
		for(int i = 0; i < tam; i++){
			// Condição que exclui caracteres especiais da manipulação mas ainda os adiciona
			if (original.charAt(i) >= ' ' && original.charAt(i) <= '~'){carac = (char)((original.charAt(i)+chave)%127);}
			else {carac = original.charAt(i);}
				manip[i] = carac;
		}
		// Conversão de char[] para String em criptografado
		criptografado = new String(manip);
	
		return criptografado;
	}			
	
	// Programa principal
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		setChave(3);
		// Loop de inserção
		String original = sc.nextLine();
		while (!(original.equals("FIM"))){
			System.out.println(cifra(original));
			original = sc.nextLine();
		}
		sc.close();
	}
}

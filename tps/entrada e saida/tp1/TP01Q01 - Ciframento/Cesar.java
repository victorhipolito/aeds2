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
		
		
		//loop de inserção em manip
		for(int i = 0; i < tam; i++){
			//int val=0;
			//if (original.charAt(i) >= 'a'){val = 97;}
			//else {val = 65;}
			manip[i] = (char)((original.charAt(i)+chave)%127);
		}	
		criptografado = new String(manip);
	
		return criptografado;
	}			

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		setChave(3);
		String original = sc.nextLine();
		while (!(original.equals("FIM"))){
			System.out.println(cifra(original));
			original = sc.nextLine();
		}
		
	}
}

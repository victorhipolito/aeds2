import java.util.Scanner;

class Inversao{
	// String manipulada
	public static String texto = new String();
	// String invertida
	public static String invertido = new String();

	private static void inversaoR(int i){
		if (i > 0){
			i--;
			invertido += texto.charAt(i);
			inversaoR(i);	
		}
	}

	public static void inversao(){
		inversaoR(texto.length());
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		texto = sc.nextLine();
		while(texto.charAt(0) != 'F' || texto.charAt(1) != 'I' || texto.charAt(2) != 'M'){
			inversao();
			System.out.println(invertido);
			invertido = new String();
			texto = sc.nextLine();
		}
	}
}

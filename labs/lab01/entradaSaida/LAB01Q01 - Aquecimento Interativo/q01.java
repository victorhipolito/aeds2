import java.util.Scanner;
class Maiusculo{
	
	//Metodos Privados
	private static String frase;
	
	//Metodos Publicos
	public static void setFrase(String texto){frase = texto;}
	public static String getFrase(){return frase;}
	public static int checkMaiuscula(){
		String texto = getFrase();
		int quantidade = 0;
		for (int i = 0; i < texto.length(); i++){
			if (texto.charAt(i) >= 'A' && texto.charAt(i) <= 'Z'){quantidade++;}
		}
		return quantidade;
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String novo = sc.nextLine();
		while(!(novo.equals("FIM"))){
			setFrase(novo);
			System.out.println("Frase:" + novo + "\nQuantidade de Maiusculas: " + checkMaiuscula());
			novo = sc.nextLine();	
		}
	}
	
}

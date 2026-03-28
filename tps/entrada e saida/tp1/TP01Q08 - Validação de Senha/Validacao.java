import java.util.Scanner;



// Estratégia -> 
// 1) Checar length()
// 2) Criar funções ehNum, ehLower, ehUpper -> se não for nenhuma dessas, é caractere especial.
class Validacao{

	public static String senha = new String();
	
	public static boolean ehNum(char c) {return (c >= '0' && c <= '9');}
	
	public static boolean ehLower(char c) {return (c >= 'a' && c <= 'z');}
	
	public static boolean ehUpper(char c) {return (c >= 'A' && c <= 'Z');}
	
	public static void main(String args[]){
		// Declaração de variáveis
		Scanner sc = new Scanner(System.in);
		boolean temNum, temLower, temUpper, temEspecial;
		char c;
		int tam=-1;
		senha = sc.nextLine();
		// Loop de execução
		while (!(senha.equals("FIM"))){
			if (tam != -1) System.out.println();
			tam = senha.length();
			// Variáveis vão definir se é ou não uma senha válida no fim
			temNum = temLower = temUpper = temEspecial = false;
			if(tam >= 8){
				// Checa todos os caracteres com as funções ehNum, ehLower e ehUpper.
				for (int i = 0; i < tam; i++){
					c = senha.charAt(i);
					if (ehNum(c)) temNum = true;
					else if (ehLower(c)) temLower = true;
					else if (ehUpper(c)) temUpper = true;
					else temEspecial = true;
				}
			}
			// Comparação final
			if (temNum && temLower && temUpper && temEspecial) System.out.print("SIM");
			else System.out.print("NAO");
			senha = sc.nextLine();
		}
		sc.close();
	}	
}

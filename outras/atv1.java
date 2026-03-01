import java.util.Scanner;

class Soma{
	
	public static int soma(int a, int b)
		{
		return a+b;
		}
	
	public static int encontraEspaco(String linha){
		int pos = -1;
		for(int i = 0; i < linha.length(); i++){
			if(linha.charAt(i) == ' '){
				pos = i;
				break;
			}
		}
		return pos;
	}

	public static int processa(String linha){
		int pos = encontraEspaco(linha);
		String a = "";
		for (int i = 0; i < pos; i++){
			a = a + linha.charAt(i);
		}
	       	String b = "";
		for (int i = ++pos; i < linha.length(); i++){
		       b = b + linha.charAt(i);
		}
		
		int x, y;
		x = Integer.parseInt(a);
		y = Integer.parseInt(b);

		return x+y;
	}

	public static void main(String args[])
		{
		Scanner sc = new Scanner(System.in);
		
		String linha = sc.nextLine();
		while(linha.equals("FIM") == false){
		System.out.println(processa(linha));
		linha = sc.nextLine();

		}
		// sc.hasNext -> caso arquivo termine.
		// compilar ustilizando arquivo .in -> java arquivo < entrada.in > saida.txt / onde saida.txt é para onde vai o resultado.
		// diff saida.txt pub.out -> compara os 2
		sc.close();
	}
}

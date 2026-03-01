import java.util.Scanner;

class Desenhar{
	public static void quadrado(int lado){
		for(int i = 1; i <= lado; i++){
			for(int j = 1; j <= lado; j++){
				if (i == 1 || i == lado){System.out.print("*");}
				else{
					if(j == 1 || j == lado){System.out.print("*");}
					else{System.out.print(" ");}
				}
			}
			System.out.println();
		}
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int lado = sc.nextInt();

		quadrado(lado);
		
		sc.close();
	}
}

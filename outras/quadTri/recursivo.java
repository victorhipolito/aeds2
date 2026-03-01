import java.util.Scanner;
import java.lang.Math;

class Desenhar{
	private static void quadrado(int lado, int i, int j){
		if(i < lado){
			if(j < lado){
				if (j%(lado-1) == 0 || i%(lado-1) == 0 || i+j == (lado/2)+1 || i+j == (lado/2)+lado-2 || Math.abs(i-j) == (lado/2)-1 || i == lado/2 || j == lado/2) {
					System.out.print("*");
				}
				else{System.out.print(" ");}	
				quadrado(lado, i, ++j);
			}
			else{
				System.out.println();
				quadrado(lado, ++i, 0);
			}
		}
	}
	
	public static void quadrado(int lado){
	       quadrado(lado, 0, 0);
       	}
	
	private static void ampulheta (int lado, int i, int j){
		int meio = lado/2;
		if (i < lado){
			if (j < lado){
				if (j >= meio-Math.abs(meio-i) && j <= meio+Math.abs(meio-i)){
					System.out.print("*");

				}
				else {System.out.print(" ");}
				ampulheta(lado, i, ++j);	
			}	
			else{
				System.out.println();
				ampulheta(lado, ++i, 0);
			}
		}
	}

	public static void ampulheta(int lado){
		ampulheta(lado, 0, 0);
	}


	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int lado = sc.nextInt();
		ampulheta(lado);
		 	
		sc.close();
	}


}

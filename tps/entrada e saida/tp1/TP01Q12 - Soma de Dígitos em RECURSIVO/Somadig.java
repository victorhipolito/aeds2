import java.util.Scanner;

class Somadig{
	
	public static int somadig(int n){
		if (n < 10) return n;
		else return (n%10 + somadig(n/10));
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int num = 0;
		while (sc.hasNextInt()){
			num = sc.nextInt();
			System.out.println(somadig(num));
		}
	}
}

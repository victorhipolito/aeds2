import java.util.Scanner;

class lab3{
	
	public static int[] lista;
	
	public static int tamanho;
		
	public static int m;

	public static void swap(int i, int j){
		int aux = lista[i];
		lista[i] = lista[j];
		lista[j] = aux;
	}

	private static void recSelecao(int i, int j, int menor){
		// CONDICOES
		if (i < tamanho - 1){
			if (j < tamanho){
				// Ordenar em relação a mod M
				if (lista[j]%m < lista[menor]%m){menor = j;} 
				else if (lista[j]%m == lista[menor]%m){
				// Entre impar e par de mod iguais, precede o impar
					if (lista[j]%2 > lista[menor]%2){menor = j;}
					// Entre 2 impares, precede o maior
					else if (lista[j] > lista[menor] && lista[j]%2 == 1){menor = j;}
					// Entre 2 pares, precede o menor
					else if (lista[j] < lista[menor] && lista[menor]%2 == 0){menor = j;} 	
				}
				recSelecao(i, ++j, menor);
			}
			else {	
				swap(i,menor);
				recSelecao(i+1, i+2, i+1);
			}	
		}
	}
	
	public static void selecao(){recSelecao(0, 1, 0);}
	
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		tamanho = sc.nextInt();
		m = sc.nextInt();
		while (tamanho != 0 && m != 0){
			System.out.println(tamanho + " " + m);	
			lista = new int[tamanho];
			for (int i = 0; i < tamanho; i++){
			lista[i] = sc.nextInt();
			}
			selecao();
			for (int i : lista){System.out.println(i);}
			tamanho = sc.nextInt();
			m = sc.nextInt();
		}
		System.out.println(tamanho + " " + m);				
	}

}

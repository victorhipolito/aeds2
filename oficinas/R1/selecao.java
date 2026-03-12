import java.util.*;

class Selecao{
	private static int[] lista;
	private static int s;
		
	public static void swap(int[] lista, int i, int j){
		int temp = lista[i];
		lista[i] = lista[j];
		lista[j] = temp; 
	}

	public static void crescente(){
		for (int i = 0; i < s; i++) {array[i]=i;}
	}
	
	public static void decrescente(){
		for (int i = 0; i < s; i++) {array[i]=n-1-i;}
	}
	
	public static void aleatorio(){
		Random rand = new Random();
		crescente();
		for (int i = 0; i < s; i++) {
			swap(lista, i, Math.abs(rand.nextInt())%s)
		}
	}
	
	public static long now(){return new Date().getTime();}

	

	public static void selecao(int[] lista){
		s = lista.length;
		int menor;
		for (int i = 0; i < s-1; i++){
			menor = i;
			for (int j = i; j < s; j++){
				if(lista[j] < lista[menor]){
				menor = j;		
				}	
			}
			swap(lista, i, menor);		
		}
	
	}
	
	public static void main(String args[]){
		s = Integer.parseInt(args[0]);
		char escolha = args[1].charAt(0);
		switch(escolha){
			case 'C':
				//Crescente		
				break;	
			case 'D':
				//Decrescente
				break;
			case 'A':
				//Aleatorio
				break;
		}	
		
		
		for (int i = 0; i < organizar.length; i++){System.out.print(organizar[i] + " - ");}
		System.out.println();
		selecao(organizar);
		for (int i = 0; i < organizar.length; i++){System.out.print(organizar[i] + " - ");}
	}
}

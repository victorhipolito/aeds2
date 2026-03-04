import java.util.Scanner;

class Selecao{
		
	public static void swap(int[] lista, int i, int j){
		int temp = lista[i];
		lista[i] = lista[j];
		lista[j] = temp; 
	}

	public static void selecao(int[] lista){
		int s = lista.length;
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
		int[] organizar = {5,24,6,3,626,778,434,88,222,46,1351,45};
		for (int i = 0; i < organizar.length; i++){System.out.print(organizar[i] + " - ");}
		System.out.println();
		selecao(organizar);
		for (int i = 0; i < organizar.length; i++){System.out.print(organizar[i] + " - ");}
	}
}

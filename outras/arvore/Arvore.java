import java.util.Scanner;

class Celula{
	public int elemento;
	public Celula prox;
	
	public Celula(int i){
		elemento = i;
		prox = null;
	}
	
	public Celula(){
		elemento = -1;
		prox = null;
	}

}

class Pilha{
	public Celula head;

	public Pilha(){
		tomp = new Celula();
	}

	public void inserir(int i){
		Celula tmp = new Celula(i);
		tmp.prox = topo.prox;
		topo.prox = tmp;
	}
	
	public int remover(){
		if (head.prox == null) return -1;
		int r = topo.prox.elemento;
		topo.prox = topo.prox.prox;
		return r;
	}

	public void mostrar(){
		Celula tmp = head;
		System.out.print("[HEAD]->");
		while(tmp.prox != null){
			System.out.print("["+tmp.prox.elemento+"]->");
			tmp = tmp.prox;
		}
		System.out.println("null");
	}
	
}




	
	

class No{
	public int elemento;	
	public No esq;
	public No dir;

	public No(int i){
		elemento = i;
		esq = dir = null;
	}
	
}

//class Arv{
	//public No Raiz



class Arvore{

	public static void main(String args){
	}
}

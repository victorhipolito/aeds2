import java.util.Scanner;

// Classe manipulação guardara funções de manipulação de valores comuns de duas ou mais classes do projeto.
class Manipulacao{
	// Converte uma parte dada de uma string para valor numérico, já que o projeto não permite o split() 
	public static int converterParte(String s, int i, int f){
		int casa = 1;
		int conv = 0;
		for (int j = f; j >= i; j++){
			conv += (s.charAt(i)-'0')*casa;
			casa *= 10;
		}
		return conv;
	}
	
	// Conta a quantidade de vezes que um caracter aparece numa string
	public static int countChar(char c, String s){
		int qts = 0;
		for (int i = 0; i < s.length(); i++) if (s.charAt(i) == c) qts++;
	}
}	

class Data{
	// Atributos de Data
	private static int ano;
	private static int mes;
	private static int dia;
	
	// Set dos atributos de data
	public static void setAno(int a){ano = a;}
	public static void setMes(int m){
		if (m > 0 && m < 13) mes = m;
		else mes = 0;
	}
	public static void setDia(int d){
		// Meses com 31 dias
		if (d > 0 && d < 32 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) dia = d;
		// Meses com 30 dias
		else if (d > 0 && d < 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) dia = d;
		// Fevereiro
		else if (mes == 2 && d > 0 && (d > 29 || (d > 30 && ano%4 == 0))) dia = d;
		else dia = 0;
	}

	public Data(){
		dia = 0;
		mes = 0;
		ano = 0;
	}

	private Data(int a, int m, int d){
		setAno(a);
		setMes(m);
		setDia(d);
	}

	public static Data parseData(String s){
		int[] data = new int[3];
		// s[0 a 3] = ano, s[5 e 6] = mes, s[8 e 9] = dia
		data[0] = Manipulacao.converterParte(s, 0, 3);
		data[1] = Manipulacao.converterParte(s, 5, 6);
		data[2] = Manipulacao.converterParte(s, 8, 9);

		return new Data(data[0], data[1], data[2]);
	}

	public static String formatar(){
		return String.format("%02d/%02d/%04d", dia, mes, ano);
	}
}

class Hora{
	private static int hora;
	private static int minuto;
	
	public static void setHora(int h){
		if (0 <= h && h < 24) hora = h;
		else hora = 99;
	}
	public static void setMinuto(int m){
		if (0 <= m && m < 60) minuto = m;
		else minuto = 99;
	}

	public Hora(){
		hora = 99;
		minuto = 99;
	}

	private Hora(int h, int m){
		setHora(h);
		setMinuto(m);
	}

	public static Hora parseHora(String s){
		//s[0] e s[1] = hora, s[3] e s[4] = minuto.
		int h = Manipulacao.converterParte(s, 0, 1);
		int m = Manipulacao.converterParte(s, 3, 4);
		
		return new Hora(h, m);
	}
	
	public String formatar(){
		return String.format("%02d:%02d", hora, minuto);	
	}	

}

class Restaurante{
	private static int id;
	private static String nome;
	private static String cidade;
	private static int capacidade;
	private static double avaliacao;
	private static String[] tipos_cozinha;
	private static int faixa_preco;
	private static Hora horario_abertura;
	private static Hora horario_fechamento;
	private static Data data_abertura;
	private static boolean aberto;
	
	// Separa a substring dos tipos_cozinha pelo separador (;)
	public static void addTipos(String s){
		// Recebe a quantidade de tipos de cozinha que há e inicializa com base nisso a array tipos_cozinha
		int qtTipos = Manipulacao.countChar(';', s);
		tipos_cozinha = new String[qtTipos];
		int loc = 0;
		tipos_cozinha[0] = new String();
		for(int i = 0; i < s.length(); i++){
			if (s.charAt(i) == ';'){
				loc++;
				tipos_cozinha[loc] = new String();
			}
			else{
				tipos_cozinha[loc] += s.charAt(i);
			}
		}
	}


	public static Restaurante parseRestaurante(String s){
		// Dividir a string em 11 substrings;
		// Tratar cada substring com parse(tipo)
		String[] auxiliar = new String[11];
		int pos = 0;
		auxiliar[0] = new String();
		for(int i = 0; i < s.length(); i++){
			if (s.charAt(i) == ','){
				pos++;
				auxiliar[pos] = new String();
			}
			else{
				auxiliar[pos] += s.charAt(i);
			}
		}

}

//class ColecaoRestaurantes{

//}

class Modelagem{

	public static void main(String args[]){
		int i = 0;
	}
}

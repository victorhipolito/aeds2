import java.util.Scanner;
import java.io.File;

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
		return qts;
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
	//Construtor vazio (não será utilizado)
	public Data(){
		dia = 0;
		mes = 0;
		ano = 0;
	}
	//Construtor de dia, mes e ano - privado, a única maneira de montar Data é através de parseData
	private Data(int a, int m, int d){
		setAno(a);
		setMes(m);
		setDia(d);
	}
	// Constrói um novo objeto Data através da string.
	public static Data parseData(String s){
		int[] data = new int[3];
		// s[0 a 3] = ano, s[5 e 6] = mes, s[8 e 9] = dia
		data[0] = Manipulacao.converterParte(s, 0, 3);
		data[1] = Manipulacao.converterParte(s, 5, 6);
		data[2] = Manipulacao.converterParte(s, 8, 9);

		return new Data(data[0], data[1], data[2]);
	}
	// Retorna a String formatada
	public static String formatar(){
		return String.format("%02d/%02d/%04d", dia, mes, ano);
	}
}

class Hora{
	private static int hora;
	private static int minuto;
	//Sets de hora - 99 será para a identificação de erro no código
	public static void setHora(int h){
		if (0 <= h && h < 24) hora = h;
		else hora = 99;
	}
	public static void setMinuto(int m){
		if (0 <= m && m < 60) minuto = m;
		else minuto = 99;
	}
	// Construtor vazio - não será utilizado
	public Hora(){
		hora = 99;
		minuto = 99;
	}
	// Construtor privado - Acessado através de parseHora
	private Hora(int h, int m){
		setHora(h);
		setMinuto(m);
	}
	// Constrói um novo ovjeto Hora com base na string
	public static Hora parseHora(String s){
		//s[0] e s[1] = hora, s[3] e s[4] = minuto.
		int h = Manipulacao.converterParte(s, 0, 1);
		int m = Manipulacao.converterParte(s, 3, 4);
		
		return new Hora(h, m);
	}
	// Retorno da hora formatada
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
	
	public int getId(){return id;}	
	private String getNome(){return nome;}
	private String getCidade(){return cidade;}
	private int getCapacidade(){return capacidade;}
	private double getAval(){return avaliacao;}
	private String[] getTC(){return tipos_cozinha;}
	private int getFP(){return faixa_preco;}
	private Hora getHA(){return horario_abertura;}
	private Hora getHF(){return horario_fechamento;}
	private Data getDA(){return data_abertura;}
	private boolean getAberto(){return aberto;}


	private Restaurante(int i, String n, String cid, int cap, double aval, String[] t_c, int f_p, Hora h_a, Hora h_f, Data d_a, boolean a){
		id = i;
		nome = n;
		cidade = cid;
		capacidade = cap;
		avaliacao = aval;
		tipos_cozinha = t_c;
		faixa_preco = f_p;
		horario_abertura = h_a;
		horario_fechamento = h_f;
		data_abertura = d_a;
		aberto = a;
	}


	// Separa a substring dos tipos_cozinha pelo separador (;)
	public static String[] parseTipos(String s){
		// Recebe a quantidade de tipos de cozinha que há e inicializa com base nisso a array tipos_cozinha
		int qtTipos = Manipulacao.countChar(';', s);
		String[] tp = new String[qtTipos];
		int loc = 0;
		for (int i = 0; i < qtTipos; i++) tp[i] = new String();
		for(int i = 0; i < s.length(); i++){
			if (s.charAt(i) == ';'){
				loc++;
			}
			else{
				tp[loc] += s.charAt(i);
			}
		}
		return tp;
	}
	
	public static Restaurante parseRestaurante(String s){
		Scanner sc = new Scanner(s);
		sc.useDelimiter(",");
		String tmp;
		// id
		id = sc.nextInt();
		// nome
		nome = sc.next();
		// cidade
		cidade = sc.next();
		// capacidade
		capacidade = sc.nextInt();
		// avaliacao
		tmp = sc.next();
		avaliacao = Double.parseDouble(tmp);
		// tipos_cozinha
		tmp = sc.next();
		tipos_cozinha = parseTipos(tmp);
		// faixa_preço
		tmp = sc.next();
		faixa_preco = tmp.length();	
		// horario_abertura
		tmp = sc.next();
		horario_abertura = Hora.parseHora(tmp);
		// horario_fechamento
		tmp = sc.next();
		horario_fechamento = Hora.parseHora(tmp);
		// data_abertura
		tmp = sc.next();
		data_abertura = Data.parseData(tmp);
		// aberto
		tmp = sc.next();
		aberto = (tmp.charAt(0) == 't');
		sc.close();
		return new Restaurante(id, nome, cidade, capacidade, avaliacao, tipos_cozinha, faixa_preco, horario_abertura, horario_fechamento, data_abertura, aberto);
	}

	public static String formatar(){
		String s = new String("[");
		// Elem. já formatados
		s += String.format("%d ## %s ## %s ## %.1lf ## [", id, nome, cidade, capacidade, avaliacao);
		//tipos_cozinha
		for (int i = 0; i < tipos_cozinha.length; i++){
			s += tipos_cozinha[i];
			if (i != tipos_cozinha.length - 1) s += ",";
			else s += "] ## ";
		}
		//faixa_preco
		for (int i = 0; i < faixa_preco; i++) s += "$";
		// Horas e datas
		s += String.format(" ## %s-%s ## %s ## ", horario_abertura.formatar(), horario_fechamento.formatar(), data_abertura.formatar());
		// Booleano
		s += (aberto) ? "true]" : "false]";

		return s;
	}
}

class ColecaoRestaurantes{
	private int tamanho;
	private static Restaurante[] restaurantes;

	public int getTamanho(){return tamanho;}
	
	public static Restaurante[] getRestaurantes(){return restaurantes;}
	
	public int findRest(int qual){
		for (int i = 0; i < getTamanho(); i++){
			if(restaurantes[i].getId() == qual) return i;
		}
		return -1;
	}
	//Path = /tmp/restaurantes.csv
	public void lerCsv(String path){
		File arquivo = new File(path);
		int n = 0;
		try (Scanner ler = new Scanner(arquivo)){
			while(ler.hasNextLine()){n++; ler.next();}
			ler.reset();
			tamanho = n;
			restaurantes = new Restaurante[n];
			for (int i = 0; i < n; n++){restaurantes[i] = Restaurante.parseRestaurante(ler.nextLine());}
			ler.close();
		}
		catch (Exception e) {System.out.println("Erro: arquivo não encontrado");}
	}

	private ColecaoRestaurantes(String cam){lerCsv(cam);}

	public static ColecaoRestaurantes lerCsv(){return new ColecaoRestaurantes("/tmp/restaurantes.csv");}
}

class Modelagem{



	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		ColecaoRestaurantes col = ColecaoRestaurantes.lerCsv();
		Restaurante[] rests = ColecaoRestaurantes.getRestaurantes();
		int r = -2;
		int pos;
		while(r != -1){
			r = sc.nextInt();
			pos = col.findRest(r);
			if (pos != -1) System.out.println(rests[pos].formatar());
			else System.out.println("Erro: Não achou o restaurante");
		}
		sc.close();	
	}

}

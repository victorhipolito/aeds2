#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct Hora{
	int hora;
	int minuto;
} Hora;

typedef struct Data{
	int ano;
	int mes;
	int dia;
} Data;

typedef struct Restaurante{
	int id;
	char* nome;
	char* cidade;
	int capacidade;
	double avaliacao;
	int n_tipos_cozinha;
	char **tipos_cozinha;
	int faixa_preco;
	Hora horario_abertura;
	Hora horario_fechamento;
	Data data_abertura;
	bool aberto;
} Rest;

typedef struct Colecao_Restaurantes{
	int tamanho;
	struct Restaurante** restaurantes;
} CRest;

//DATA_FUNCTIONS
Data parse_data(char* s){
	Data nova_data;
	int d = 0;int m = 0;int a = 0;
	a = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
	m = (s[5]-'0')*10 + (s[6]-'0');
	d = (s[8]-'0')*10 + (s[9]-'0');

	nova_data.ano = a; nova_data.mes = m; nova_data.dia = d;	

	return nova_data;
}

void formatar_data(Data* data, char* buffer){
	sprintf(buffer, "%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

int datacmp(Data* d1, Data* d2){
	if(d1->ano < d2->ano) {return -1;}
	else if(d1->ano > d2 ->ano) {return 1;}

	if(d1->mes < d2->mes) {return -1;}
	else if(d1->mes > d2 ->mes) {return 1;}
	
	if(d1->dia < d2->dia) {return -1;}
	else if(d1->dia > d2 ->dia) {return 1;}

	return 0;
}	

//HORA_FUNCTIONS
Hora parse_hora(char* s){
	Hora nova_hora;
	int h = 0;
	int m = 0;
	h = (s[0]-'0')*10 + (s[1]-'0');
	m = (s[3]-'0')*10 + (s[4]-'0');
	nova_hora.hora = h;
	nova_hora.minuto = m;
	return nova_hora;
}

void formatar_hora(Hora* hora, char* buffer){
	sprintf(buffer, "%02d:%02d", hora->hora, hora->minuto);	
}

//RESTAURANTE_FUNCTIONS
Rest* parse_restaurante(char* s){
	//Alocacao do restaurante e ponteiros internos.
	Rest* rest = (Rest*)malloc(sizeof(Rest));
	rest->nome = (char*)malloc(50*sizeof(char));
	rest->cidade = (char*)malloc(50*sizeof(char));
	rest->n_tipos_cozinha = 2;
	rest->tipos_cozinha = (char**)malloc(rest->n_tipos_cozinha*sizeof(char*));
	rest->tipos_cozinha[0] = (char*)malloc(25*sizeof(char));
	rest->tipos_cozinha[1] = (char*)malloc(25*sizeof(char));
	//Criação de strings de suporte
	char* faixa_str = (char*)malloc(5*sizeof(char));
	char* h_a_str = (char*)malloc(5*sizeof(char));
	char* h_f_str = (char*)malloc(5*sizeof(char));
	char* data_ab_str = (char*)malloc(11*sizeof(char));
	char* aberto_str = (char*)malloc(6*sizeof(char));
	//Leitura dos dados
	sscanf(s, "%d,%[^,],%[^,],%d,%lf,%[^;];%[^,],%[^,],%[^-]-%[^,],%[^,],%s", &rest->id, rest->nome, rest->cidade, &rest->capacidade, &rest->avaliacao, rest->tipos_cozinha[0], rest->tipos_cozinha[1], faixa_str, h_a_str, h_f_str, data_ab_str, aberto_str);
	// Tratamento dos dados
	rest->faixa_preco = strlen(faixa_str);
	rest->horario_abertura = parse_hora(h_a_str);
	rest->horario_fechamento = parse_hora(h_f_str);
	rest->data_abertura = parse_data(data_ab_str);
	rest->aberto = (aberto_str[0] == 't');
	//Limpeza
	free(faixa_str);free(h_a_str);free(h_f_str);free(data_ab_str);free(aberto_str);
	return rest;
}

void formatar_restaurante(Rest* restaurante, char* buffer){
	char* cifrao = (char*)malloc(5*sizeof(char));
	for (int i = 0; i <= restaurante->faixa_preco; i++){
		if(i == restaurante->faixa_preco) cifrao[i] = '\0';
		else cifrao[i] = '$';
	}
	char* h_a_format = (char*)malloc(6*sizeof(char)); 
	char* h_f_format = (char*)malloc(6*sizeof(char)); 
	char* d_a_format = (char*)malloc(11*sizeof(char));
	char* aberto_format = (char*)malloc(6*sizeof(char));
	formatar_hora(&restaurante->horario_abertura, h_a_format); 
	formatar_hora(&restaurante->horario_fechamento, h_f_format);
	formatar_data(&restaurante->data_abertura, d_a_format);
	(restaurante->aberto) ? sprintf(aberto_format, "true") : sprintf(aberto_format, "false");
	sprintf(buffer, "[%d ## %s ## %s ## %d ## %.1lf ## [%s,%s] ## %s ## %s-%s ## %s ## %s]", restaurante->id, restaurante->nome, restaurante->cidade, restaurante->capacidade, restaurante->avaliacao, restaurante->tipos_cozinha[0], restaurante->tipos_cozinha[1], cifrao, h_a_format, h_f_format, d_a_format, aberto_format);
	free(cifrao); free(h_a_format); free(h_f_format); free(d_a_format); free(aberto_format);
}

//COLECAO_RESTAURANTES_FUNCTIONS
void ler_csv_colecao(CRest* c, char* path){
	// Abrir o arquivo
	FILE* arquivo;
	arquivo = fopen(path, "r");
	//Inicializar os ponteiros de restaurantes
	c->restaurantes = (Rest**)malloc(c->tamanho*sizeof(Rest*));
	// String de suporte
	char* linha = (char*)malloc(125*sizeof(char));
	//Pulando a primeira linha
	fgets(linha, 124*sizeof(char), arquivo);
	//Leitura e alocação nos restaurantes
	for (int i = 0; i < 500; i++){
		fgets(linha, 124*sizeof(char), arquivo);
		c->restaurantes[i] = parse_restaurante(linha);
	}
	fclose(arquivo);	
}

CRest* ler_csv(){
	CRest* rests = (CRest*)malloc(sizeof(CRest));
	char path[] = "/tmp/restaurantes.csv"; 
	rests->tamanho = 500;	
	ler_csv_colecao(rests, path);
	return rests;
}

// FUNCAO FIND COM A CHAVE ID
int find_rest_by_id(CRest* c, int t_id){
	int resp;
	for (resp = 0; resp < c->tamanho; resp++){if (c->restaurantes[resp]->id == t_id) return resp;}
	return -1;
}

//SWAP
void swap(Rest** r, int i, int j){
	Rest* aux = r[i];
	r[i] = r[j];
	r[j] = aux;
}

//PARCIAL - INSERÇÃO
void insercao_parcial(Rest** r, int k, int tam){
	// Codigo para benchmark
	FILE *log = fopen("./902693_insercao_parcial.txt", "w+");
	clock_t ini, fim;
	ini = clock();
	int comp = 0;
	int mov = 0;
	// Execução por si do programa
	Rest* tmp;
	for (int i = 1; i < tam; i++){
		tmp = r[i];
		int j = (i < k) ? i-1 : k-1;
		while((j >= 0) && (strcmp(r[j]->cidade, tmp->cidade) > 0)){
			comp++; // Benchmark
			r[j+1] = r[j];
			mov++; // Benchmark
			j--;
		}
		comp++; // Benchmark
		r[j+1] = tmp;
		mov++; // Benchmark
	}
	// Operações finais e escrita no arquivo de log os valores necessarios.
	fim = clock();
	double microsec = CLOCKS_PER_SEC/1000000;
	double tempo_microsegundos = ((double)(fim-ini))/microsec;

	fprintf(log, "902693\t%d\t%d\t%.5lf", comp, mov, tempo_microsegundos);
	fclose(log);
}

//PARCIAL - HEAPSORT
//CONSTRUIR HEAP INVERTIDO
void construir_heap(Rest** rest, int tam, int* comparacoes, int* movimentacoes){
	for(int i = tam; i > 0 && datacmp(&rest[i]->data_abertura, &rest[i]->data_abertura) > 0; i/=2){
		swap(rest, i,i/2);
		*comparacoes += 1;
		*movimentacoes += 1;
	}
	*comparacoes += 1;
}
//HAS FILHO - HEAP INVERTIDO
bool has_filho(int i, int tam){
	return (i <= (tam/2));
}
//GET MAIOR FILHO - HEAP INVERTIDO
int get_maior_filho(Rest** r, int i, int tam, int* comparacoes){
	int filho;
	int aux = datacmp(&r[2*i]->data_abertura, &r[2*i+ 1])
	*comparacoes += 1;
	if(2*i == tam || aux > 0) {filho = 2*i;}
	else if(aux == 0) {
		*comparacoes += 1;
		if (strcmp(r[2*i]->nome, r[2*i+ 1]->nome) > 0) {filho = 2*i;}
		else {filho = 2*i+ 1;}
	}
	else {filho = 2*i+ 1;}
	return filho
}


void heapsort_parcial(Rest** r, int k, int tam, int* comparacoes, int* movimentacoes){
	// Codigo para benchmark
	FILE *log = fopen("./902693_insercao_parcial.txt", "w+");
	clock_t ini, fim;
	ini = clock();
	int comp = 0;
	int mov = 0;
	// Execução por si do programa
	for (int i = 1; i < tam; i++){
		tmp = r[i];
		int j = (i < k) ? i-1 : k-1;
		while((j >= 0) && (strcmp(r[j]->cidade, tmp->cidade) > 0)){
			comp++; // Benchmark
			r[j+1] = r[j];
			mov++; // Benchmark
			j--;
		}
		comp++; // Benchmark
		r[j+1] = tmp;
		mov++; // Benchmark
	}
	// Operações finais e escrita no arquivo de log os valores necessarios.
	fim = clock();
	double microsec = CLOCKS_PER_SEC/1000000;
	double tempo_microsegundos = ((double)(fim-ini))/microsec;

	fprintf(log, "902693\t%d\t%d\t%.5lf", comp, mov, tempo_microsegundos);
	fclose(log);
}

// MAIN
int main(){
	char* buffer = (char*)malloc(150*sizeof(char));
	int i;
	CRest* colecao = ler_csv();
	Rest** rest = (Rest**)malloc(500*sizeof(Rest*));
	int tam = 0;
	scanf("%d", &i);
	while(i != -1){
		rest[tam] = colecao->restaurantes[find_rest_by_id(colecao, i)];
		tam++;
		scanf("%d", &i);
	}

	insercao_parcial(rest, 10, tam);

	for (int j = 0; j < tam; j++){formatar_restaurante(rest[j], buffer); printf("%s\n", buffer);}
		
	return 0;
}


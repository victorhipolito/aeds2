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

typedef struct Celula{
	Rest* elem;
	struct Celula* prox;
} Cel;

typedef struct Lista{
	Cel* ini;
	Cel* fim;
	int tam;
} Lista;

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
	rest->nome = (char*)malloc(60*sizeof(char));
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

//Lista Flexivel
Cel* new_cel(Rest* r){
	Cel* new = (Cel*)malloc(sizeof(Cel));
	new->elem = r;
	new->prox = NULL;
	return new;
}

Lista* new_lista(){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
	return l;
}

// Funções de inserir
void inserir_inicio(Lista* l, Rest* r){
	Cel* new = new_cel(r);
	new->prox = l->ini;
	l->ini = new;
	if (l->tam == 0){l->fim = l->ini;}
	l->tam += 1;
}

void inserir_fim(Lista* l, Rest* r){
	Cel* new = new_cel(r);
	if(l->fim != NULL){
		l->fim->prox = new;
		l->fim = new;
	}
	else {l->ini = new; l->fim = l->ini;}
	l->tam += 1;
}

void inserir(Lista* l, Rest* r, int pos){
	if (pos == 0){inserir_inicio(l,r);}
	else if (pos == l->tam){inserir_fim(l,r);}
	else{
		Cel* new = new_cel(r);
		Cel* aux = l->ini;
		for (int i = 1; i < pos; i++){aux = aux->prox;}
		new->prox = aux->prox;
		aux->prox = new;
		l->tam += 1;
	}
}

// Funções de remover
char* remover_inicio(Lista* l){
	Cel* aux = l->ini;
	l->ini = l->ini->prox;
	char* nome = aux->elem->nome;
	free(aux);
	l->tam -= 1;
	return nome;
}

char* remover_fim(Lista* l){
	Cel* aux = l->ini;
	Cel* rem;
	char* nome;
	while(aux->prox != l->fim){aux = aux->prox;}
	rem = aux->prox;
	aux->prox = NULL;
	l->fim = aux;
	nome = rem->elem->nome;
	l->tam -= 1;
	free(rem);
	return nome;
}

char* remover(Lista* l, int pos){
	char* nome;
	if (l->tam == 0){nome = remover_inicio(l);}
	if (l->tam == pos){nome = remover_fim(l);}
	else{
		Cel* aux = l->ini;
		Cel* rem;
		for (int i = 1; i < pos; i++){aux = aux->prox;}
		rem = aux->prox;
		aux->prox = aux->prox->prox;
		nome = rem->elem->nome;
		l->tam -= 1;
		free(rem);
	}
	return nome;
}

// MAIN
int main(){
	int i;
	CRest* colecao = ler_csv();
	Lista* l = new_lista();
	scanf("%d", &i);
	while(i != -1){
		inserir_fim(l, colecao->restaurantes[find_rest_by_id(colecao, i)]);
		scanf("%d", &i);
	}
	
	int reg, pos_lista, pos_rest;
	char comando[5];
	char* retorno = (char*)malloc(60*sizeof(char));
	scanf("%d", &reg);
	for(int i = 0; i < reg; i++){
			scanf(" %s", comando);
			switch(comando[1]){
				// Caso remover() ou inserir()
				case '*':
					scanf(" %d", &pos_lista);
					if(comando[0] == 'I'){
						scanf(" %d", &pos_rest);
						inserir(l, colecao->restaurantes[find_rest_by_id(colecao, pos_rest)], pos_lista);
					}
					else{
						retorno = remover(l, pos_lista);
						printf("(R)%s\n", retorno);
					}
					break;
				// Caso remover_inicio() ou inserir_inicio()
				case 'I':
					if(comando[0] == 'I'){
						scanf(" %d", &pos_rest);
						inserir_inicio(l, colecao->restaurantes[find_rest_by_id(colecao, pos_rest)]);
					}
					else{
						retorno = remover_inicio(l);
						printf("(R)%s\n", retorno);
					}
					break;
				// Caso remover_fim() ou inserir_fim()
				case 'F':
					if (comando[0] == 'I'){
						scanf(" %d", &pos_rest);
						inserir_fim(l, colecao->restaurantes[find_rest_by_id(colecao, pos_rest)]);
					}
					else{
						retorno = remover_fim(l);
						printf("(R)%s\n", retorno);
					}
					break;
				}
			}

	Cel* tmp = l->ini;
	char* buffer = (char*)malloc(150*sizeof(char));
	while(tmp != NULL){
		formatar_restaurante(tmp->elem, buffer);
		printf("%s\n", buffer);
		tmp = tmp->prox;
	}
		
	return 0;
}

/*

Alunos: Adam Roger Slabadack, Daniel Wzoreck
Curso: Análise e Desenvolvimento de Sistemas - IFSC
Disciplina: Estrutura de Dados

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
	char nome[50];
	float preco;
	struct Produto *proxProd;
} Produto;

typedef struct Item {
	int qtde;
	Produto *p;
	struct Item *proxItem;
} Item;

typedef struct Venda {
	char data[10];
	Item *itens;
	struct Venda *proxVenda;
} Venda;

void cadastrarProdutos(Produto **produtos); // OK
void listarProdutos(Produto *p); // OK
void cadastrarProduto(Produto **p); // OK
void editarProduto(Produto **p);
void deletarProduto(Produto **p, int indice);

int main() {

	Produto *produtos = NULL;
	Venda *vendas = NULL;

	cadastrarProdutos(&produtos);
	listarProdutos(produtos);
	cadastrarProduto(&produtos);
	listarProdutos(produtos);

	return 0;
}

void listarProdutos(Produto *p) {
	Produto *aux = p;
	while(aux != NULL) {
		printf("\nEndereço: %p", aux);
		printf("\nProduto: %s", aux->nome);
		printf("\nPreço: %.2f", aux->preco);
		printf("\nProximo Produto: %p\n", aux->proxProd);
		aux = aux->proxProd;
	}
}

void cadastrarProduto(Produto **p) {
	Produto *novo = (Produto*) malloc(sizeof(Produto));
	printf("\nInforme o nome do Produto: ");
	scanf("%s", novo->nome);
	printf("Informe o valor: ");
	scanf("%f", &novo->preco);
	novo->proxProd = *p;
	*p = novo;
}

void cadastrarProdutos(Produto **produtos) {
	Produto *auxProd;
	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Monitor");
	auxProd->preco = 700;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Mouse");
	auxProd->preco = 80;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Teclado");
	auxProd->preco = 50;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Headset");
	auxProd->preco = 80;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Placa de Video GTX-1660");
	auxProd->preco = 1200;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Processador i5");
	auxProd->preco = 1300;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Memoria Ram DDR4 8GB");
	auxProd->preco = 250;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "SSD 240GB");
	auxProd->preco = 250;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Placa Mae LGA-1151");
	auxProd->preco = 500;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "Fonte de Energia 600W");
	auxProd->preco = 180;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;
}

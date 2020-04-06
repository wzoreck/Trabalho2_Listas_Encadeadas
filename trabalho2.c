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

void cadastrarProdutos(Produto **produtos);

int main() {

	// Ponteiro p/ lista de Produtos e auxiliar
	Produto *produtos = NULL;

	cadastrarProdutos(&produtos);

	// Exibir ultimo produto
	printf("Endereço: %p", produtos);
	printf("\nProduto: %s", produtos->nome);
	printf("\nPreço: %.2f", produtos->preco);
	printf("\nProximo Produto: %p\n", produtos->proxProd);

	return 0;
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

// Continuar
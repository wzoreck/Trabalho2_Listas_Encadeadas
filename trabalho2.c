/*

Alunos: Adam Roger Slabadack, Daniel Wzoreck
Curso: Análise e Desenvolvimento de Sistemas - IFSC
Disciplina: Estrutura de Dados

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto
{
	char nome[50];
	float preco;
	struct Produto *proxProd;
} Produto;

typedef struct Item
{
	int qtde;
	Produto *p;
	struct Item *proxItem;
} Item;

typedef struct Venda
{
	char data[10];
	Item *itens;
	struct Venda *proxVenda;
} Venda;

void cadastrarProdutos(Produto **produtos); // OK
void listarProdutos(Produto *p);			// OK
void cadastrarProduto(Produto **p);			// OK
void editarProduto(Produto **p, char nome[50]); // OK
void deletarProduto(Produto **p, int indice); // OK - PRECISA DE REVISÃO NO NOME DAS VARIÁVEIS

int main()
{

	Produto *produtos = NULL;
	Venda *vendas = NULL;

	cadastrarProdutos(&produtos);
	listarProdutos(produtos);

	return 0;
}

void listarProdutos(Produto *p)
{
	Produto *aux = p;
	while (aux != NULL)
	{
		printf("\nEndereço: %p", aux);
		printf("\nProduto: %s", aux->nome);
		printf("\nPreço: %.2f", aux->preco);
		printf("\nProximo Produto: %p\n", aux->proxProd);
		aux = aux->proxProd;
	}
}

void cadastrarProduto(Produto **p)
{
	Produto *novo = (Produto *)malloc(sizeof(Produto));
	printf("\nInforme o nome do Produto: ");
	scanf("%s", novo->nome);
	printf("Informe o valor: ");
	scanf("%f", &novo->preco);
	novo->proxProd = *p;
	*p = novo;
}

void editarProduto(Produto **p, char nome[50])
{
	Produto *aux = *p;
	while (aux != NULL)
	{
		if(strcmp(aux->nome, nome) == 0)
		{
			printf("\n\nInforme o novo nome do produto: ");
			scanf("%s", aux->nome);
			printf("Informe o novo preço do produto: ");
			scanf("%f", &aux->preco);
			return;
		}
		aux = aux->proxProd;
	}
}

void cadastrarProdutos(Produto **produtos)
{
	Produto *auxProd;
	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "monitor");
	auxProd->preco = 700;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "mouse");
	auxProd->preco = 80;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "teclado");
	auxProd->preco = 50;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "headset");
	auxProd->preco = 80;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "placa_de_video");
	auxProd->preco = 1200;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "processador");
	auxProd->preco = 1300;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "memoria_ram");
	auxProd->preco = 250;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "ssd");
	auxProd->preco = 250;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "placa_mae");
	auxProd->preco = 500;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;

	auxProd = (Produto *)malloc(sizeof(Produto));
	strcpy(auxProd->nome, "fonte");
	auxProd->preco = 180;
	auxProd->proxProd = *produtos;
	*produtos = auxProd;
}

void deletarProduto(Produto **p, int indice)
{
	if (indice < 0)
		return;
	else if (*p == NULL)
		return;
	else if (indice == 0)
	{
		Produto *aux = *p;
		*p = aux->proxProd;
		free(aux);
		return;
	}
	else
	{
		Produto *aux = *p;
		int indiceAux = 0;
		while (aux != NULL && indiceAux < indice - 1)
		{
			aux = aux->proxProd;
			indiceAux++;
		}
		if (indiceAux < indice - 1 || aux->proxProd == NULL)
			return;
		Produto *aux2 = aux->proxProd;
		aux->proxProd = aux2->proxProd;
		free(aux2);
		return;
	}
}
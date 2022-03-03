#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int num;
	struct Node* next;
} node;

void add(node* inicio);
void remover(node* inicio);
void exibir(node* inicio);

int main(void) {

	node* inicio = (node*)malloc(sizeof(node));
	inicio->next = NULL;
	int opcao;

	do
	{
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Exibir\n");
		printf("0 - Sair\n");
		printf("Digite a opcao desejada:\n");

		scanf_s("%d", &opcao);

		switch (opcao)
		{
		case 1:
			add(inicio);
			break;
		case 2:
			remover(inicio);
			break;
		case 3:
			exibir(inicio);
			break;
		default:
			break;
		}
	} while (opcao != 0);
	

	return 0;
}

void add(node* inicio) {
	node* novoNo = (node*)malloc(sizeof(node));
	novoNo->next = NULL;

	printf("Qual numero deseja inserir?\n");
	scanf_s("%d", &novoNo->num);

	node* aux = inicio;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}

	aux->next = novoNo;
}

void remover(node* inicio) {
	node* noAnterior = inicio;
	node* aux = inicio;
	while (aux->next != NULL)
	{
		noAnterior = aux;
		aux = aux->next;
	}

	noAnterior->next = NULL;
}

void exibir(node* inicio) {
	node* aux = inicio;
	if (inicio->next == NULL)
	{
		printf("Lista vazia\n");
		return;
	}
	do {
		aux = aux->next;
		printf_s("%d\n", aux->num);
	} while (aux->next != NULL);
}



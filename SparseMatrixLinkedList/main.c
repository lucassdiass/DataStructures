/*
 * main.c
 *
 *  Created on: Sep 20, 2018
 *      Author: lucas
 */
#include "SparseMatrixLinkedList.h"
#include <stdio.h>
int main()
{
	esparsa *espars=NULL;
	int i =0, l=0,c=0,v=0, opcao=0;;
	espars=inicio(espars,-1,-1,0);
	for(;i<tam;i++)
	{
		espars=inicio(espars,-1,i,0);
	}
	//espars=inicio(espars,0,-1,-1);
	for(i=0;i<tam;i++)
	{
		espars=inicio(espars,i,-1,0);
	}

	do
	{
		for(int i = 0; i < tam; i++)
				exibir_l(espars,i);
		printf("1 -> Alterar dados da matriz\n");
		printf("2 -> Consultar valor de uma posição\n");
		printf("3 -> Mostrar conteúdo de uma linha\n");
		printf("4 -> Mostrar conteúdo de uma coluna na matriz original\n");
		printf("5 -> Somar triangulo superior\n");
		printf("0 -> Sair\n");
		printf("digite uma opcao:\n");
		scanf("%d", &opcao);


		if(opcao==1)
		{
			printf("Linha \n");
			scanf("%d", &l);
			printf("Coluna\n");
			scanf("%d", &c);
			printf("Valor \n");
			scanf("%d", &v);
			espars=alterar(espars,l,c,v);
		}
		else if(opcao==2)
		{
			printf("Linha \n");
			scanf("%d", &l);
			printf("Coluna\n");
			scanf("%d", &c);
			if(l >= tam || c>=tam || c <0 || l < 0)
				printf("linha ou coluna inválidos");
			else
				printf("O valor na linha %d - coluna %d: %d\n",l,c,consultar(espars,l,c));
		}
		else if (opcao == 3)
		{
			printf("Linha \n");
			scanf("%d", &l);
			if(l<tam && l >= 0)
				exibir_l(espars,l);
			else
				printf("Opção invalida\n");
		}
		else if(opcao ==4)
		{
			printf("Coluna\n");
			scanf("%d", &c);
			if(c<tam)
				exibir_c(espars,c);
			else
				printf("Opção invalida\n");
		}
		else if(opcao == 5)
		{
			printf("Soma do triangulo superior: %d\n",trianguloSuperior(espars));
		}
		else if(opcao==0)
		{
			eliminar(espars);
		}
	}while(opcao);

	return 0;
}







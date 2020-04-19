/*
 * operacoes.c
 *
 *  Created on: Sep 20, 2018
 *      Author: lucas
 */
#include "SparseMatrixLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

esparsa *inicio(esparsa *m, int l, int c,int v)
{
	esparsa *novo=NULL, *inicio =NULL, *aux=NULL, *direita=NULL, *abaixo=NULL,*aux_d=NULL;
	if(l >=tam || c >= tam)
	{
		return NULL;
	}

	novo=malloc(sizeof(esparsa));
	novo->linha=l;
	novo->coluna=c;
	novo->valor=v;
	if(m==NULL)
	{
		novo->abaixo=novo;
		novo->direita=novo;

		return novo;
	}

	inicio=m;

	/*
	 * encontrar a coluna e armazenar na variavel direita
	 */
	do
	{
		if(novo->coluna==m->coluna)
		{
			direita=m;
		}
		m=m->direita;
	}while(m->direita!=inicio);

	/*
	 * se direita for igual a null significa que nao encontrou a coluna
	 */

	if(direita==NULL)
	{
		novo->abaixo=novo;
		if(novo->linha==m->linha)
		{
			m->direita=novo;
			novo->direita=inicio;
		}
		else
		{
			abaixo=m;
			while(novo->linha != abaixo->linha && abaixo->abaixo!=m ) abaixo=abaixo->abaixo;
			if(novo->linha == abaixo->linha)
			{
				aux=abaixo;
				while(novo->coluna < abaixo->coluna && abaixo->direita!=aux) abaixo=abaixo->direita;
				if(abaixo->direita == aux)
				{
					abaixo->direita=novo;
					novo->direita=aux;
				}
				else if(novo->coluna > abaixo->coluna)
				{
					aux=abaixo->direita;
					novo->direita=aux;
					abaixo->direita=novo;
				}
			}

		}
		//return inicio;
	}
	else
	{
		/*
		 * aqui a coluna já está encontrada
		 */
		aux=direita;
		while(novo->linha > direita->abaixo->linha && direita->abaixo != aux)
		{

			direita=direita->abaixo;
		}

		novo->direita=novo;
		if(novo->linha < direita->abaixo->linha)
		{
			novo->abaixo=direita->abaixo;
			direita->abaixo=novo;
		}
		if(direita->abaixo==aux)
		{
			direita->abaixo=novo;
			novo->abaixo=aux;
		}

	}

	return inicio;
}

esparsa *alterar(esparsa *m, int l, int c, int v)
{
	esparsa * novo = NULL, *aux=NULL, *direita=NULL, *abaixo=NULL, *ini=NULL, *aux2=NULL;
	if( l >= tam  || c >= tam || c <0 || l < 0)
	{
		return m;
	}
	ini=m;
	do
	{
		if(m->linha==l)
		{
			abaixo=m;
			do
			{
				if(abaixo->direita->coluna==c)
				{
					if(v)
					{
						abaixo=abaixo->direita;
						abaixo->valor=v;
						return ini;
					}
					else
					{
						aux=direita=abaixo->direita;
						do
						{
							direita=direita->direita;
						}while(direita->direita!=aux);

						direita->direita=aux->direita;
						aux2=aux;
						do
						{
							aux2=aux2->abaixo;
						}while(aux2->abaixo!=aux);
						aux2->abaixo=aux->abaixo;

						free(aux);
						return ini;
					}
				}
				abaixo=abaixo->direita;
			}while(abaixo!=m);
		}
		m=m->abaixo;
	}while(m!=ini);

	m=ini;
	if(v==0)
		return ini;
	novo=malloc(sizeof(esparsa));
	novo->linha=l;
	novo->coluna=c;
	novo->valor=v;

	do
	{
		m=m->direita;
	}while(m->coluna!=novo->coluna);

	abaixo=m;
	do
	{
		m=m->abaixo;
	}while(m->abaixo!=abaixo && novo->linha > m->abaixo->linha);

	if(m->abaixo==abaixo)
	{
		m->abaixo=novo;
		novo->abaixo=abaixo;
	}
	else if(m->abaixo->linha < novo->linha)
	{
		novo->abaixo=m->abaixo;
		m->abaixo=novo;
	}
	direita=ini;
	while(direita->linha!=novo->linha) direita=direita->abaixo;
	aux=direita;
	do
	{
		direita=direita->direita;
	}while(direita->direita!=aux && novo->linha > direita->direita->linha );

	if(direita->direita==aux)
	{
		novo->direita=aux;
		direita->direita=novo;
	}
	else
	{
		novo->direita=direita->direita;
		direita->direita=novo;
	}
	return ini;
}


void eliminar(esparsa * e)
{
	esparsa *aux=NULL, *col=NULL, *aux2=NULL, *limpa=NULL;
	if(e==NULL)
		exit(1);
	aux=e;
	do
	{
		aux2=col=e;
		e=e->direita;
		printf("limpando coluna %d \n", col->coluna);
		do
		{
			limpa=col;
			col=col->abaixo;
			printf("%d ", limpa->valor);
			free(limpa);
		}while(aux2!=col);
		printf("\n");
	}while(e!=aux);
}

int consultar(esparsa *e,int l, int c)
{
	esparsa *aux=NULL, *aux2=NULL, *x=NULL;
	if(e==NULL)
		return 0;
	aux=e;
	do
	{
		if(aux->linha==l)
		{
			x=aux;
			do
			{
				if(x->coluna==c)
					return x->valor;
				x=x->direita;
			}while(x!=aux);
		}
		aux=aux->abaixo;
	}while(aux!=e);
	return 0;
}

void exibir_l(esparsa *e, int l)
{
	esparsa *aux=NULL, *x=NULL;
	int valor = 0;
	if(e!=NULL)
	{
		aux=e;
		do
		{
			if(aux->linha==l)
			{
				x=aux;
				for(int a = 0 ;a < tam; a++)
				{
					do
					{
						if(x->coluna==a)
							valor=x->valor;
						x=x->direita;
					}while(x!=aux);
					printf("%d ", valor);
					valor = 0;
				}
			}
			aux=aux->abaixo;
		}while(aux!=e);
	}
	printf("\n");
}

void exibir_c(esparsa *e, int c)
{
	esparsa *aux=NULL, *x=NULL;
	int valor = 0;
	if(e!=NULL)
	{
		aux=e;
		do
		{
			if(aux->coluna==c)
			{
				x=aux;
				for(int a = 0 ;a < tam; a++)
				{
					do
					{
						if(x->linha==a)
							valor=x->valor;
						x=x->abaixo;
					}while(x!=aux);
					printf("%d\n", valor);
					valor = 0;
				}
			}
			aux=aux->direita;
		}while(aux!=e);
	}
	printf("\n");
}

int trianguloSuperior(esparsa *e)
{
	int soma=0;
	esparsa *aux=NULL, *aux2=NULL;
	aux=e;
	for(int l = 0; l < tam; l++)
	{
		do
		{
			if(aux->linha==l)
			{
				for(int c = l; c < tam; c++)
				{
					aux2=aux;
					do
					{
						if(aux2->coluna==c)
						{
							soma+= aux2->valor;
						}
						aux2=aux2->direita;
					}while(aux2!=aux);
				}
			}
			aux=aux->abaixo;
		}while(aux!=e);
	}
	return soma;
}

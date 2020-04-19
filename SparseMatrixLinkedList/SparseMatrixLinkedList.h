/*
 * trabEstrutura.h
 *
 *  Created on: Sep 20, 2018
 *      Author: lucas
 */

#ifndef TRABESTRUTURA_H_
#define TRABESTRUTURA_H_
#define tam 4
typedef struct elemento
{
	struct elemento *direita, *abaixo;
	int valor, linha, coluna;
} esparsa;

esparsa *alterar(esparsa *, int l, int c, int v);
esparsa *inicio(esparsa *, int l, int c, int v);
int consultar(esparsa *,int l, int c);
void exibir_l(esparsa *, int l);
void exibir_c(esparsa *, int c);
int trianguloSuperior(esparsa *);
void eliminar(esparsa *);
#endif /* TRABESTRUTURA_H_ */

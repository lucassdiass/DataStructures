/*
 * main.c
 *
 *  Created on: 30 de mar de 2020
 *      Author: lucas
 */
#include "AVL.h"
#define MAX 20
int main()
{
	struct AVL * tree=NULL;
	srand(time(NULL));
	for(int x = 0; x < MAX;x++)
	{
		tree=insertNode(tree,rand()%100);
		order(tree,0);
		printf("\n\n");
	}

	clear(&tree);
	return 0;
}




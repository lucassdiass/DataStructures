/*
 * AVL.c
 *
 *  Created on: Mar 1, 2020
 *      Author: lucas
 */
#include "AVL.h"

struct AVL * insertNode(struct AVL *in, int key)
{
	struct AVL * novo=NULL;
	if(in==NULL)
	{
		novo=(struct AVL*)malloc(sizeof(struct AVL));
		novo->key=key;
		novo->lef=novo->rig=NULL;
		novo->fe=0;
		return novo;
	}
	if(key>in->key)
		in->rig=insertNode(in->rig,key);
	else if(key<in->key)
		in->lef=insertNode(in->lef,key);
	else
		return in;
	in->fe=contNivel(in->rig)-contNivel(in->lef);
	if(in->fe>1)
	{
		if(in->rig->fe<0)
		{
			in->rig=rotLeft(in->rig);
		}
		in=rotRight(in);
	}
	if(in->fe < -1)
	{
		if(in->lef->fe>0)
		{
			in->lef=rotRight(in->lef);
		}
		in=rotLeft(in);
	}
	return in;
}

//raiz é o nó que é pai e vai ser filho
struct AVL * rotRight( struct AVL * parent)
{
	struct AVL * root=NULL;
	if(parent==NULL)
	{
		return parent;
	}
	if(parent->rig!=NULL)
	{
		root=parent->rig;
		parent->rig=root->lef;
		root->lef=parent;
		root->fe=contNivel(root->rig)-contNivel(root->lef);
		parent->fe=contNivel(parent->rig)-contNivel(parent->lef);
	}
	return root;
}
struct AVL * rotLeft(struct  AVL * parent)
{
	struct AVL * root=NULL;
	if(parent==NULL)
	{
		return parent;
	}
	if(parent->lef!=NULL)
	{
		root=parent->lef;
		parent->lef=root->rig;
		root->rig=parent;
		root->fe=contNivel(root->rig)-contNivel(root->lef);
		parent->fe=contNivel(parent->rig)-contNivel(parent->lef);
	}
	return root;
}
int contNivel(struct AVL *in)
{
	int d=0,e=0, n=1;
	if(in==NULL)
	{
		return 0;
	}
	d=contNivel(in->rig);
	e=contNivel(in->lef);
	return (d>e)? n+d : e+n;
}
void clear(struct AVL **root)
{
	if((*root)!=NULL)
	{
		clear(&(*root)->lef);
		clear(&(*root)->rig);
		if(&(*root)->rig==NULL && &(*root)->lef==NULL)
		{
			free(*root);
			*root=NULL;
		}
	}
}

void order(struct AVL *in, int n)
{
	if(in!=NULL)
	{
		order(in->lef, (n+1));
		for(int x = 0; x<n;x++)
		{
			printf("-");
		}
		printf("%d fe:%d\n", in->key, in->fe);
		order(in->rig, (n+1));
	}
}
void posorder(struct AVL *in, int n)
{
	if(in!=NULL)
	{
		order(in->lef, (n+1));
		order(in->rig, (n+1));
		for(int x = 0; x<n;x++)
		{
			printf("-");
		}
		printf("%d fe:%d\n", in->key, in->fe);

	}
}
void preorder(struct AVL *in, int n)
{
	if(in!=NULL)
	{
		order(in->rig, (n+1));
		order(in->lef, (n+1));
		for(int x = 0; x<n;x++)
		{
			printf("-");
		}
		printf("%d fe:%d\n", in->key, in->fe);

	}
}

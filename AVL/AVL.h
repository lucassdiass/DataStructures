/*
 * AVL.h
 *
 *  Created on: Mar 1, 2020
 *      Author: lucas
 */

#ifndef AVL_H_
#define AVL_H_
#include <stdlib.h>
#include <stdio.h>
typedef struct AVL
{
	int key, fe;
	struct AVL  * rig, *lef;
};
/*
 * @brief: Insert new node in AVL
 * @param: struct AVL * - Pointer to root
 * @param: int - value of key
 * @return: AVL with new node
 */
struct AVL * insertNode(struct AVL *, int);

/*
 * @brief: rotation between the parent node and the child on the right
 * @param: struct AVL * parent - Pointer to parent
 * @return: child on the right  being a parent node
 */
struct AVL * rotRight(struct AVL * parent);
/*
 * @brief: otation between the parent node and the child on the left
 * @param: struct AVL * - Pointer to parent
 * @return: child on the left  being a parent node
 */
struct AVL * rotLeft(struct  AVL * parent);
/*
 * @brief: Calculate height from tree
 * @param:struct AVL * - tree will be count
 * @return: height from tree
 */
int contNivel(struct AVL *);
/*
 * @brief: clear the memory
 * @param: reference to AVL tree
 */
void clear(struct AVL **);
/*
 * @brief: print the three: left child, parent, right child
 * @param: struct AVL * -  pointer to root from AVL tree
 * @param: int - amount of blanks, always call with value 0
 */
void order(struct AVL *, int );


/*
 * @brief: print the three:  right child, left child parent,
 * @param: struct AVL * - pointer to root from AVL tree
 *  @param: int - amount of blanks, always call with value 0
 */
void preorder(struct AVL *, int );


/*
 * @brief: print the three:  left child, right child parent,
 * @param: struct AVL * - pointer to root from AVL tree
 *  @param: int - amount of blanks, always call with value 0
 */
void posorder(struct AVL *, int );

//void balancearArvore(AVL**);


#endif /* AVL_H_ */

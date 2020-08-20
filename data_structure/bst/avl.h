#ifndef AVL_H
#define AVL_H

#define MAX(x, y) (x > y ? x : y)
#define GET_HEIGHT(node) (node == NULL ? 0 : (node)->height)
#define GET_BALFACTOR(node) (node == NULL ? 0 : GET_HEIGHT((node)->left) - GET_HEIGHT((node)->right))

typedef struct avlNode {
	int height;
	int value;
	struct avlNode *left;
	struct avlNode *right;
} avlNode;

typedef struct avlTree {
	avlNode *root;
} avlTree;



void *insertRecursion(avlNode **root, avlNode *node);
avlNode *insertRec2(avlNode *root, avlNode *node);
void removeNode(avlNode **root, int value);
avlNode *insertNode(avlNode **root,  avlNode *newNode);
#endif

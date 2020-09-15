#ifndef BST_H
#define BST_H
typedef struct bstNode {
	int value;
	struct bstNode *left;
	struct bstNode *right;
} bstNode;

typedef struct bstTree {
	bstNode *root;
} bstTree;

bstNode *insertNode(bstTree *tree, int value);
void *insertRecursion(bstNode **root, bstNode *node);
bstNode *insertRec2(bstNode *root, bstNode *node);
int removeMinNode(bstNode **root);
void removeNode(bstNode **root, bstNode *node);

#endif

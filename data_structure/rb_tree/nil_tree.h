#ifndef RB_TREE_H
#define RB_TREE_H

typedef enum color {
	BLACK = 0,
	RED = 1
} color;
#define isRed(node) (node->color == RED)
#define isBlack(node) (node->color == BLACK)
#define uncleNode(node) (\
		node->parent == node->parent->parent->left ? node->parent->parent->right : node->parent->parent->left\
		)

#define grandNode(node) (node->parent->parent)


typedef struct rbNode {
	int value;
	color color;
	struct rbNode *parent;
	struct rbNode *left;
	struct rbNode *right;
} rbNode;

typedef struct rbTree {
	rbNode *root;
	rbNode *nil;
} rbTree;

void initRbTree(rbTree *tree);
void insertNode(rbTree *tree, rbNode *node);
void deleteNode(rbTree *tree, int value);
// void insertNode2(rbNode **root, rbNode *node);
// void deleteNode(rbNode **root, int value);
#endif

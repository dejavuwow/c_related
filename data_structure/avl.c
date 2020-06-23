#include <stdio.h>
#include <stdlib.h>
#define AVL_LEFT_HEAVY 2
#define AVL_RIGHT_HEAVY -2

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct Avl {
	Node *root;

} Avl;

static int getLeftHeight(Node *node)
{
	int height = 0;
	while (node->left != NULL)
	{
		height++;
		node = node->left;
	}
	return height;
}



static int getRightHeight(Node *node)
{
	int height = 0;
	while (node->right != NULL)
	{
		height++;
		node = node->right;
	}

	return height;
}

static int getNodeBalFactor(Node *node)
{
	return getLeftHeight(node) - getRightHeight(node);
}

static int insert(Avl *tree, int value)
{
	Node *node = tree->root;
	Node *temp = node;

	Node newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) return -1;
	newNode->value = value;

	while (1)
	{
		if (node->value > value)
		{
			if (node->left != NULL)
				node = node->left;
			else
			{
				node->left = newNode;
				break;
			}
		}
		else
		{
			if (node->right != NULL)
				node = node->right;
			else
			{
				node->right = newNode;
				break;
			}
		}
		
	}
	return 0;
}

static Node *getParentNode(Avl *tree, Node *node)
{
	Node *root = tree->root;
	Node *parent = NULL;
	while (root != NULL)
	{
		if (root->left == node || root->right == node)
		{
			parent = root;
			break;
		}

		else {
			if (root->value > node->value) root = root->left;
			else root = root->right;
		}
	}
	return NULL;
	/**
	if (root == NULL) return NULL;
	if (root->left == node || root->right == node) return root;
	if (root->value > node->value)
		getParentNode(root->left, node);
	else
		getParentNode(root->right, node);
	*/
}

Node *getMinNode(Node *node)
{
	if (node == NULL) return NULL;
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}
static int removeNode(Avl *tree, Node *delNode)
{
	Node *parent, *min;

	
	if (delNode->left == NULL || delNode->right == NULL)
	{
		parent = getParentNode(tree->root, delNode);
		if (delNode == tree->root) {
			if (delNode->left != NULL) tree->root = delNode->left;
			if (delNode->right != NULL) tree->root = delNode->right;
			tree->size--;
			free(delNode);
		}
		else {
			if (delNode->left != NULL) parent->left = delNode->left;
			if (delNode->right != NULL) parent->right = delNode->right;
		}
				
	}
	else {
		min = getMinNode(delNode->right);
		parent = getParentNode(delNode, min);
		delNode->value = parent->value;
		if (delNode->right == min)
			parent->right = min->right;
		else
			parent->left = min->right;
	}
}

int main(void)
{
	 Node root;
	 root.value = 20;

	 return 0;

}

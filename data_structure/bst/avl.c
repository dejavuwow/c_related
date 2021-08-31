#include "./avl.h"
#include  <stdlib.h>
#include <math.h>
#include <stdio.h>

//LL旋转
static avlNode *LL(avlNode *root)
{

	avlNode *temp = root->left;

	root->left = temp->right;
	temp->right = root;

	root->height = MAX(GET_HEIGHT(root->left), GET_HEIGHT(root->right)) + 1;

	temp->height = MAX(GET_HEIGHT(temp->left), GET_HEIGHT(temp->right)) + 1;

	return temp;
}

//RR旋转
static avlNode *RR(avlNode *root)
{
	avlNode *temp = root->right;

	root->right = temp->left;
	temp->left = root;

	root->height = MAX(GET_HEIGHT(root->left), GET_HEIGHT(root->right)) + 1;

	temp->height = MAX(GET_HEIGHT(temp->left), GET_HEIGHT(temp->right)) + 1;

	return temp;
}

//LR旋转
//    0
//   0
//    0
static avlNode *LR(avlNode *root)
{
	root->left = RR(root->left);
	return LL(root);
}

//RL旋转
// 0
//  0
// 0
static avlNode *RL(avlNode *root)
{
	root->right = LL(root->left);
	return RR(root);
}



static avlNode *setbalance(avlNode *root)
{
	int factor = GET_BALFACTOR(root);
	if (factor > 1 && GET_BALFACTOR(root->left) == 1)
	{
		return LL(root);
	}
	else if (factor > 1 && GET_BALFACTOR(root->left) == -1)
	{
		return LR(root);
	}
	else if (factor < - 1 && GET_BALFACTOR(root->right) == -1)
	{
		return RR(root);
	}
	else if (factor < -1 && GET_BALFACTOR(root->right)== 1)
	{
		return RL(root);
	}
	else
		return root;
}
//递归插入1
void *insertRecursion(avlNode **root, avlNode *node)
{
	if (*root == NULL)
		*root = node;
	else
	{
		if ((*root)->value > node->value)
			insertRecursion(&(*root)->left, node);
		else
			insertRecursion(&(*root)->right, node);
	}
	(*root)->height = MAX(GET_HEIGHT((*root)->left), GET_HEIGHT((*root)->right)) + 1;
	*root = setbalance(*root);
}

//递归插入2
avlNode *insertRec2(avlNode *root, avlNode *node)
{
	if (root == NULL)
	{
		return node;
	}
	else
	{
		if (root->value > node->value)
			root->left = insertRec2(root->left, node);
		else
			root->right = insertRec2(root->right, node);
	}
	return setbalance(root);
}

//迭代版插入
avlNode *insertNode(avlNode **root,  avlNode *newNode)
{
	avlNode *croot = *root;
	if (root == NULL) {
		*root = newNode;
	}
	else {
		while (1)
		{
			if (croot->value > newNode->value)
			{
				if (croot->left == NULL) {
					croot->left = newNode;
					break;
				}
				else
					croot = croot->left;
			}
			else {
				if (croot->right == NULL) {
					croot->right = newNode;
					break;
				}
				else
					croot = croot->right;
			}
		}

	}
	return newNode;

}

static void removeMinNode(avlNode *find, avlNode **root)
{
	if ((*root)->left == NULL)
	{
		find->value = (*root)->value;
		free(*root);
		*root = (*root)->right;
	}
	else {
		removeMinNode(find, &(*root)->left);
		(*root)->height = MAX(GET_HEIGHT((*root)->left), GET_HEIGHT((*root)->right)) + 1;
		(*root) = setbalance(*root);
	}

}
//递归版删除节点
void removeNode(avlNode **root, int value)
{
	if (*root == NULL) return;
	else {
		if ((*root)->value == value)
		{
			if ((*root)->right == NULL)
			{
				free(*root);
				*root = (*root)->left;
			}
			else {
				removeMinNode(*root, &(*root)->right);
			}
		}
		else{


			if((*root)->value > value)
				removeNode(&(*root)->left, value);
			else
				removeNode(&(*root)->right, value);

			(*root)->height = MAX(GET_HEIGHT((*root)->left), GET_HEIGHT((*root)->right)) + 1;
			(*root) = setbalance(*root);
		}
	}

}

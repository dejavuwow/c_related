#include "./bst.h"
#include <stdlib.h>
#include <stdio.h>

//insert 迭代版
bstNode *insertNode(bstNode *root, int value)
{
	bstNode newNode = (bstNode*)malloc(sizeof(bstNode));

	if (bstNode == NULL) return NULL;
	newNode->left = newNode->right = NULL;
	newNode->value = value;
	if (root == NULL) {
		tree->root = newNode;
	}
	else {
		while (1)
		{
			if (root->value > value)
			{
				if (root->left == NULL) {
					root->left = newNode;
					break;
				}
				else
					root = root->left;
			}
			else {
				if (root->right == NULL) {
					root->right = newNode;
					break;
				}
				else
					root = root->right;
			}
		}

	}
	return newNode;

}

//递归版
void *insertRecursion(bstNode **root, bstNode *node)
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

}

//递归版2

bstNode *insertRec2(bstNode *root, bstNode *node)
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
	return root;
}
int removeMinNode(bstNode **root)
{
	bstNode *temp = *root;
	bstNode **save = &temp;

	while (temp->left != NULL)
	{
		save = &temp;
		temp = temp->left;
	}
	free(*save);
	*save = temp->right;
	return (*save)->value;
}
//递归版删除节点
void removeNode(bstNode **root, bstNode *node)
{
	if (*root == NULL) return;
	else {
		if ((*root)->value == node->value)
		{
			if ((*root)->right == NULL)
			{
				free(*root);
				*root = (*root)->left;
			}
			else {
				(*root)->value = removeMinNode((*root)->right);
			}
		}
		else if((*root)->value > node->value)
			removeNode(&(*root)->left, node);
		else
			removeNode(&(*root)->right, node);
	}
}


//删除节点逻辑
/** 1、删除节点是否为叶子节点
 * 	2、如果为叶子节点（即左右子节点皆为NULL）
 * 	3、那么仅需要将该节点的父节点的该子节点赋值为NULL,再释放该节点的内存
 * 	4、这一步需要判断该节点是否位根节点，如果位根节点，则仅需要把根节点赋值为NULL
 *
 * 	1、如果节点存在子节点需要考虑两种情况
 * 	 (节点只存在一个子节点，左右两个子节点都存在)
 *
 * 	2、如果只存在一个子节点,只需要把该子节点赋值给节点的父节点
 * 	3、判断节点是否为根节点，如果为根节点，需要把子节点设置为根节点
 *
 * 	2、如果左右子节点均存在，则找到该节点右子树中的最小节点。将该最小节点的数据赋给该节点。然后删除该最小节点
 * 	（该节点只有右子树或者无子树，要么为该节点的直接右子节点，要么是某个节点的左子节点）
 *
 *
 * 
 *
 * */

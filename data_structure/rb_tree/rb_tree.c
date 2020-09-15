#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "./rb_tree.h"

//LL
static void LL(rbNode **pRoot, rbNode *root)
{
	rbNode *parent = root->parent;
	rbNode *temp = root->left;

	root->left = temp->right;
	if (temp->right != NULL)
		temp->right->parent = root;

	temp->right = root;
	root->parent = temp;

	if (parent != NULL)
	{
		if (parent->left == root)
			parent->left = temp;
		else
			parent->right = temp;
	}
	else {
		*pRoot = temp;
	}
	temp->parent = parent;
}

//RR
static void RR(rbNode **pRoot, rbNode *root)
{
	rbNode *parent = root->parent;
	rbNode *temp = root->right;

	root->right = temp->left;
	if (temp->left != NULL)
		temp->left->parent = root;

	temp->left = root;
	root->parent = temp;

	if (parent != NULL)
	{
		if (parent->left == root)
			parent->left = temp;
		else
			parent->right = temp;
	}
	else {
		*pRoot = temp;
	}
	temp->parent = parent;
}

/** static rbNode *setbalance(rbNode **root, rbNode **pRoot) */
/** { */
/**     if (!(*root)->left && !(*root)->right) return *root; */
/**  */
/**     if (isRed((*root)->left) && isRed((*root)->right)) */
/**     { */
/**  */
/**         (*root)->left->color = (*root)->right->color = BLACK; */
/**         (*root)->color = RED; */
/**     } */
/**     if (isRed((*root)->left) && isRed((*root)->left->right)) */
/**     { */
/**         (*root)->left = RR((*root)->left); */
/**     } */
/**     if (isRed((*root)->right) && isRed((*root)->right->left)) */
/**     { */
/**         (*root)->right == LL((*root)->right); */
/**     } */
/**     if (isRed((*root)->right) && isRed((*root)->right->right)) */
/**     { */
/**         *root = RR(*root); */
/**         (*root)->color = BLACK; */
/**         (*root)->left->color = RED; */
/**  */
/**     } */
/**     if (isRed((*root)->left) && isRed((*root)->left->left)) */
/**     { */
/**         *root = LL(*root); */
/**         (*root)->color = BLACK; */
/**         (*root)->right->color = RED; */
/**     } */
/**  */
/**     if (*root == *pRoot) (*root)->color = BLACK; */
/**  */
/**     return *root; */
/**  */
/** } */

void setInsertBalance(rbNode **root, rbNode *node)
{
	while (isRed(node->parent))
	{
		if (node->parent == grandNode(node)->left)
		{
			if (isRed(uncleNode(node)))
			{

				node->parent->color = uncleNode(node)->color = BLACK;
				grandNode(node)->color = RED;
				node = grandNode(node);
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					RR(root, node);
				}
				node->parent->color = BLACK;
				grandNode(node)->color = RED;
				LL(root, grandNode(node));
			}

		}
		else {
			if (isRed(uncleNode(node)))
			{

				node->parent->color = uncleNode(node)->color = BLACK;
				grandNode(node)->color = RED;
				node = grandNode(node);
			}
			else 
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					LL(root, node);
				}
				node->parent->color = BLACK;
				grandNode(node)->color = RED;
				RR(root, grandNode(node));
			}
		}
	}
}
void insertNode(rbNode **root, rbNode *node)
{
	rbNode *current = *root;
	if (current == NULL) 
		*root = node;
	else {
		while (1) {
			if (current->value > node->value)
			{
				if (current->left == NULL)
				{
					current->left = node;
					node->parent = current;
					break;
				}
				else
					current = current->left;
			}
			else {
				if (current->right == NULL)
				{
					current->right = node;
					node->parent = current;
					break;
				}
				else
					current = current->right;

			}
		}	
	}
	setInsertBalance(root, node);
	(*root)->color = BLACK;
}

void insertNode2(rbNode **root, rbNode *node)
{
	rbNode *parent;
	rbNode **current;

	if (*root == NULL)
		*root = node;
	else {
		current = root;
		parent = (*current)->parent;
		while (1) {
			if (*current == NULL) {
				*current = node;
				node->parent = parent;
				break;
			}
			else {
				parent = *current;
				if ((*current)->value > node->value)
				{
					current = &(*current)->left;
				}
				else {
					current = &(*current)->right;
				}
			}
		}
	}

	setInsertBalance(root, node);
	(*root)->color = BLACK;
}

static rbNode *getMinNode(rbNode *node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

static void setDeleteBalance(rbNode **root, rbNode *current)
{
	rbNode *brother;
	while (isBlack(current) && current != *root)
	{
		if (current == current->parent->left)
		{
			brother = current->parent->right;
			if (brother->color == RED)
			{
				brother->color = BLACK;
				current->parent->color = RED;
				RR(root, current->parent);
			}
			else
			{
				if (isBlack(brother->left) && isBlack(brother->right))
				{
					brother->color = RED;
					current = current->parent;
				}
				else 
				{
					if (isBlack(brother->right))
					{
						LL(root, brother);
						brother->color = RED;
						brother->parent->color = BLACK;
						brother = brother->parent;
					}

					brother->color = brother->parent->color;
					brother->right->color = BLACK;
					brother->parent->color = BLACK;
					RR(root, brother->parent);
					current =  *root;
				}
			}
		}
		else 
		{
			brother = current->parent->left;
			if (brother->color == RED)
			{
				brother->color = BLACK;
				current->parent->color = RED;
				RR(root, current->parent);
			}
			else
			{
				if (isBlack(brother->left) && isBlack(brother->right))
				{
					brother->color = RED;
					current = current->parent;
				}
				else 
				{
					if (isBlack(brother->left))
					{
						RR(root, brother);
						brother->color = RED;
						brother->parent->color = BLACK;
						brother = brother->parent;
					}

					brother->color = brother->parent->color;
					brother->left->color = BLACK;
					brother->parent->color = BLACK;
					LL(root, brother->parent);
					current =  *root;
				}
			}
		}
	}
	current->color = BLACK;
}

void deleteNode(rbNode **root, int value)
{
	rbNode *deleted = *root;
	rbNode *replaced;
	rbNode *temp;
	while (1) {
		if (deleted->value == value)
		{
			if (deleted->right == NULL)
			{
				replaced = deleted->left;
			}
			else {
				temp = getMinNode(deleted->right);
				deleted->value = temp->value;
				deleted = temp;
				replaced = deleted->right;
			}
			break;
		}
		else {
			if (deleted->value > value)
				deleted = deleted->left;
			else
				deleted = deleted->right;
		}
	}
	if (deleted->parent->left == deleted)
		deleted->parent->left = replaced;
	else
		deleted->parent->right = replaced;

	if (replaced != NULL)
		replaced->parent = deleted->parent;

	if (deleted->color == BLACK)
		setDeleteBalance(root, replaced);

	free(deleted);
}

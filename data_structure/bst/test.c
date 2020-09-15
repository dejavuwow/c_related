#include <stdio.h>
#include <stdlib.h>
#include "./avl.h"
#define isEmpty(queue) (queue->head == queue->end)
typedef struct queue {
	avlNode *list[50];
	int head;
	int end;
} queue;

//init
void queueInit(queue *list)
{
	list->head = 0;
	list->end = 0;
}

void enqueue(queue *list, avlNode *node)
{
	list->list[++list->end] = node;
}

avlNode *dequeue(queue *list)
{
	return list->list[++list->head];
}

void traverse(avlNode *node, queue *list)
{
	avlNode *temp;
	enqueue(list, node);

	while (!isEmpty(list))
	{
		temp = dequeue(list);
		printf("%d\t", temp->value);
		if (temp->left){
			enqueue(list, temp->left);
		} 
		if (temp->right) {
			enqueue(list, temp->right);
		} 
	}

}
void traverse2(avlNode *root)
{
	if (root == NULL) return;
	printf("%d\t", root->value);
	traverse2(root->left);
	traverse2(root->right);
}
//         	 78 					12							13
//        12 	872				 6	   32					  6   78
//     7   	 13				  4	   7 13  78					4  7 32 872
//	 6   	    32						    872						 
//4    
int main(void)
{
	int array[] = {78, 12, 7, 13, 32, 6, 872, 4};
	avlTree mainTree;
	avlNode *node;

	mainTree.root = (avlNode*)malloc(sizeof(avlNode));
	mainTree.root->value = array[0];
	mainTree.root->left = mainTree.root->right = NULL;
	mainTree.root->height = 1;
	
	for (int i = 1; i < 8; i++)
	{
		node = (avlNode *)malloc(sizeof(avlNode));
		node->value = array[i];
		node->height = 1;
		node->left = node->right = NULL;
		insertRecursion(&mainTree.root, node);

	}
	queue *list = (queue *)malloc(sizeof(queue));
	queueInit(list);
	removeNode(&mainTree.root, 12);
	/** traverse2(mainTree.root); */
	traverse(mainTree.root, list);
	return 0;

}

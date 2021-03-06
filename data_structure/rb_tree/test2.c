#include <stdio.h>
#include <stdlib.h>
#include "./nil_tree.h"
#define isEmpty(queue) (queue->head == queue->end)
typedef struct queue {
	rbNode *list[50];
	int head;
	int end;
} queue;

//init
void queueInit(queue *list)
{
	list->head = 0;
	list->end = 0;
}

void enqueue(queue *list, rbNode *node)
{
	list->list[++list->end] = node;
}

rbNode *dequeue(queue *list)
{
	return list->list[++list->head];
}

void traverse(rbNode *node, queue *list)
{
	rbNode *temp;
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
void traverse2(rbNode *root, rbNode *nil)
{
	if (root == nil) return;
	printf("%d**%d\t", root->value, root->color);
	traverse2(root->left, nil);
	traverse2(root->right, nil);
}
//         	 78 					12							13                
//        12 	872				 6	   32					  6   78           12     872
//     7   	 13				  4	   7 13  78					4  7 32 872      6     32
//	 6   	    32						    872						       4   7  13
//4    
//   78                             12             12               12
// 12   32                       7    78         7   78           6     32
//6   13   872                  6    32             13         4    7  13   78
//4 7                              13                                          872
int main(void)
{
	/** int array[] = {78, 12, 7, 13, 32, 6, 872, 4 }; */
	int array[] = {78, 12, 7, 13, 32, 6, 872, 4};
	/** 78, 12, 7, 13, 32, 6, 872, 4 */
	rbTree mainTree;
	rbNode *node;

	initRbTree(&mainTree);
	
	for (int i = 0; i < 8; i++)
	{
		node = (rbNode *)malloc(sizeof(rbNode));
		node->value = array[i];
		node->color = RED;
		node->parent = node->left = node->right = mainTree.nil;
		insertNode(&mainTree, node);

	}
	/** queue *list = (queue *)malloc(sizeof(queue)); */
	/** queueInit(list); */
	/** removeNode(&mainTree.root, 12); */
	traverse2(mainTree.root, mainTree.nil);
	putchar('\n');
	deleteNode(&mainTree, 872);
	deleteNode(&mainTree, 78);
	traverse2(mainTree.root, mainTree.nil);
	/** traverse(mainTree.root, list); */
	return 0;

}

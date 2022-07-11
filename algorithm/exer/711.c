typedef struct Queue {
	struct TreeNode *list[0x400];
	int head;
	int end;
};
typedef struct Stack {
	struct TreeNode *list[0x800];
	int top;
};
#define QUEUE_EMPTY(queue) (queue.head > queue.end)
#define STACK_EMPTY(stack) (stack.top >= 0)
#define PUSH_STACK(stack, item) (stack.list[++stack.top] = item)
#define POP_STACK(stack) (stack.list[stack.top--])
#define ENQUEUE(queue, item) (queue.list[++queue.end % 0x400] = item)
#define DEQUEUE(queue) (queue.list[queue.head++ % 0x400])

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
	struct TreeNode *current;
	Queue queue;
	queue.head = 0;
	queue.end = -1;
	struct TreeNode **ret = malloc(sizeof(struct TreeNode*) * 0x800);
	int length = 0;

	while (!QUEUE_EMPTY(queue)) {
		struct TreeNode *list = malloc(sizeof(struct TreeNode) * 0x400);
		
		if (current->right) {
			queue[++end % 0x400] = current->right;
			stack[++top] = current->right;
		}
		if (current->left) {
			queue[++end % 0x400] = current->left;
			stack[++top] = current->right;
		}
	}
}

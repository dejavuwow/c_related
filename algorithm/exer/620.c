void recoverTree(struct TreeNode* root){

}
//     3
//   4   5
//     2
//4325
//123456
//
//153426
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL) || p->val != q-> val) return false;
	else if (p == NULL && q == NULL) return true;
	return isSameTree(p->left, q->left) && isSameTree(p->right, p->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	struct TreeNode queue1[100], queue2[100];
	int head1 = 0, end1 = -1,
		head2 = 0, end2 = -1;

	queue1[++end1] = p;
	queue2[++end2] = q;
	while (end1 >= head1 && end2 >= head2) {
		struct TreeNode *node1 = queue1[head1++];
		struct TreeNode *node2 = queue2[head2++];
		if (node1 == NULL) {
			if (node2 != NULL) return false;
		}
		else {
			if (node2 == NULL) return false;
			else if (node1->val != node2->val) return false;
			else {
				queue1[++end1] = node1->left;
				queue1[++end1] = node1->right;
				queue2[++end2] = node2->left;
				queue2[++end2] = node2->right;
			}
		}
	}
	return true;
}
int *inorderCopy, *postorderCopy, postIndex;
struct TreeNode *build(int start, int end, int rootIndex) {
	if (start > end) return NULL;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	int i;
	for (i = start; i <= end; i++) {
		if (inorderCopy[i] == postorderCopy[postIndex]) break;
	}
	root->val = inorderCopy[i];
	postIndex--;
	root->right = build(i + 1, end);
	root->left = build(start, i - 1);
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	inorderSize = inorder;
	postorderCopy = postorder;
	postIndex = postorderSize - 1;

	return build(0, inorderSize - 1);

}


//中序遍历中，遵循  前驱节点 -> 当前节点 -> 后驱节点  第一个节点一定是最左侧的叶子节点
//后续遍历中 前一个节点 一定是后一个节点的 （右节点 -> 左节点 -> 最近的有左子树的节点的左节点） 最后一个节点一定是树的根节点
//inorder = [12,5,11,21,24,3,2,15,1,20,4,7,8], postorder = [12,21,24,11, 5, 2,1, 15, 4,8, 7, 20, 3]
//             3
//		5    	  20	  
//	12   11    15	  7
//		21 24 2   1  4 8
#define NEW_NODE(value, root) {\
	root = malloc(sizeof(struct TreeNode));\
	root->val = value;\
	root->left = NULL;\
	root->right = NULL;\
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
	struct TreeNode *stack[postorderSize], *root, *ret, *left;
	int top = -1;
	int inorderIndex = inorderSize - 1;
	NEW_NODE(postorder[postorderSize - 1], root);
	ret = root;
	stack[++top] = root;
	for (int i = postorderSize - 2; i >= 0; i--) {
		if (stack[top]->val != inorder[inorderIndex]) {
			NEW_NODE(postorder[i], root);
			stack[top]->right = root;
			stack[++top] = root;
		}
		else {
			while (top >= 0 && stack[top]->val == inorder[inorderIndex]) {
				root = stack[top--];
				inorderIndex--;
			}
			NEW_NODE(postorder[i], left);
			root->left = left;
			stack[++top] = left;
		}
	}
	return ret;
}

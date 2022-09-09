int finalMax;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int maxSub(struct TreeNode *root) {
	int leftContribution = maxSub(root->left),
		rightContribution = maxSub(root->right);
	
	int max = root->val + (leftContribution <= 0 ? 0 : leftContribution) + (rightContribution <= 0 ? 0 : rightContribution);
	finalMax = MAX(max, finalMax);
	int subMax = MAX(leftContribution, rightContribution)
	return root->val + subMax > 0 ? subMax : 0;
}
int maxPathSum(struct TreeNode* root){
	finalMax = INT_MIN;
	maxSub(root);
	return finalMax;
}
//[9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
//1234
//abc
//"hit" -> "hot" -> "dot" -> "dog" -> "cog" 
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
 //cog -> c    dog / log
 void func(char *str, int index, int k) {
	 if (rest.length == 0) return;
	 if (str == endWord && index <= minLen) {
		ret[retLen++] = 
		minLen = index;
	 }
	 for (int i = ) {
		j = match(rest[i], str, k);
		list[index] = rest[i];
		func(rest[i], ++index, j);
	 }
 }
 char *** findLadders(char * beginWord, char * endWord, char ** wordList, int wordListSize, int* returnSize, int** returnColumnSizes){
	

}

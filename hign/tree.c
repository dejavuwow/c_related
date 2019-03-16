static Trnode * MakeNode(const Item *pi)
{
	Trnode *new_node;
	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}
bool AddItem(const Item *pi, Tree *ptree)
{
	Trnode *new_node;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full.\n");
		return false;
	}

	if (SeekItem(pi,ptree).child != NULL)
	{
		fprintf(stderr, "Atempted to add duplicate item\n");
		return false;
	}

	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}
	ptree->size++;
	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node,ptree->root);

	return true;

}


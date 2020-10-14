#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node* make_node(int data)
{
	Node *ptr = new Node();
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void inorder_traversal_recursive(Node *root)
{
	if(root!=NULL)
	{
		inorder_traversal_recursive(root->left);
		cout<<root->data<<" ";
		inorder_traversal_recursive(root->right);
	}
}


int main()
{
	Node *root = NULL;
	root = make_node(1);
	root->left = make_node(2);
	root->right = make_node(3);
	root->left->left = make_node(4);
	root->left->right = make_node(5);
	inorder_traversal_recursive(root);

	return 0;
}
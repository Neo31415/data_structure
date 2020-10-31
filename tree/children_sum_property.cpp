#include <iostream>
#include <stack>
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

bool children_sum_property(Node *root)
{
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	int sum = 0;
	if(root->left)
		sum+=root->left->data;
	if(root->right)
		sum+=root->right->data;

	return(root->data==sum && children_sum_property(root->left) && children_sum_property(root->right));
}

int main()
{
//     1
//    / \      
//   2   3
//  / \
// 4   5 
	Node *root = NULL;
	root = make_node(14);
	
	root->left = make_node(5);
	root->right = make_node(9);

	root->left->left = make_node(2);
	root->left->right = make_node(3);

	root->right->left = make_node(4);
	root->right->right = make_node(5);
	cout<<children_sum_property(root);
	return 0;
}
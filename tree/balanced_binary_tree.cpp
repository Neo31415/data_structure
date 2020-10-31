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

int balanced_binary_tree(Node *root)
{
	if(root==NULL)
		return 0;
	int lh = balanced_binary_tree(root->left);
	if(lh==-1) return -1;
	int rh = balanced_binary_tree(root->right);
	if(rh==-1) return -1;
	if(abs(lh-rh)>1)
		return -1;
	else
		return max(lh,rh)+1;
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
	root->right->right->right = make_node(6);
	root->right->right->right->right = make_node(7);

	if(balanced_binary_tree(root)==-1)
		cout<<"Unbalanced Tree"<<endl;
	else
		cout<<"Balanced Tree!!"<<endl;
	return 0;
}
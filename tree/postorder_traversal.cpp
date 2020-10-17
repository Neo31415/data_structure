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

void postorder_traversal_recursive(Node *root)
{
	if(root!=NULL)
	{
		postorder_traversal_recursive(root->left);
		postorder_traversal_recursive(root->right);
		cout<<root->data<<" ";
	}
}


// From GFG
void preorder_traversal_iterative(Node *root) 
{
	stack <Node *> s1,s2;
	s1.push(root);
	Node *node;
	while(!s1.empty())
	{
		node = s1.top();
		s1.pop();
		s2.push(node);
		if(node->left)
			s1.push(node->left);
		if(node->right)
			s1.push(node->right);
	}
	while(!s2.empty())
	{
		node = s2.top(); 
		cout<<node->data<<" ";
		s2.pop();
	}
}

int main()
{
//     1
//    / \      
//   2   3
//  / \
// 4   5 
	Node *root = NULL;
	root = make_node(1);
	
	root->left = make_node(2);
	root->right = make_node(3);

	root->left->left = make_node(4);
	root->left->right = make_node(5);

	root->right->left = make_node(6);
	root->right->right = make_node(7);

	preorder_traversal_iterative(root);

	return 0;
}
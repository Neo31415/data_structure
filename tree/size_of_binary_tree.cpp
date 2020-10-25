#include <iostream>
#include <queue>
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

// Iterative
int size_of_binary_tree(Node *root)
{
	if(root==NULL)
		return 0;
	int count=0;
	Node *curr;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		curr = q.front();
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
		count++;
		q.pop();
	}
	return count;
}

// Recursive
int getSize(Node *root)
{
	if(root==NULL)
		return 0;
	return 1+getSize(root->left)+getSize(root->right);
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

	cout<<"Size of Binary Tree: "<<getSize(root)<<endl;

	return 0;
}
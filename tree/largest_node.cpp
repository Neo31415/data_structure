#include <iostream>
#include <bits/stdc++.h>
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


int largest_node(Node *root)
{
	if(root==NULL)
		return INT_MIN;
	else
		return max(root->data ,max(largest_node(root->left),largest_node(root->right)) );
}


int largest_node_iterative(Node *root)
{
	Node *curr;
	stack <Node *> s;
	s.push(root);
	int val = root->data;
	while(!s.empty())
	{
		curr = s.top();
		s.pop();
		if(curr->left)
			s.push(curr->left);
		if(curr->right)
			s.push(curr->right);
		val = max(curr->data,val);
	}
	return val;
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
	cout<<largest_node_iterative(root);

	return 0;
}
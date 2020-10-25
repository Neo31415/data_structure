#include<iostream>
#include<queue>

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
	ptr->left = ptr->right = NULL;
	return ptr;
}


void level_order_traversal(Node *root)
{
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
		cout<<curr->data<<" ";
		q.pop();
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
	root->left->right->left = make_node(6);
	root->left->right->right = make_node(7);
	level_order_traversal(root);
	return 0;
}
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


int maximum_width_of_binary_tree(Node *root)
{
	Node *curr;
	int i;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	int width=0,width1;
	while(q.size()>1)
	{
		curr = q.front();
		q.pop();
		if(curr==NULL)
		{
			q.push(NULL);
			width = max(width,int(q.size()));
		}
		else
		{	
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
	}
	return width-1;
}

int main()
{
	Node *root = NULL;
	root = make_node(1);
	root->left = make_node(2);
	root->right = make_node(3);
	root->left->left = make_node(4);
	root->left->right = make_node(5);
	root->right->left = make_node(6);
	root->right->right = make_node(7);
	cout<<maximum_width_of_binary_tree(root)<<endl;
	return 0;
}
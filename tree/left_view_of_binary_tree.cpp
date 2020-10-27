#include <iostream>
#include <queue>
using namespace std;

int max_level = 0;

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

void left_view_of_binary_tree_recursive(Node *root, int level)
{
	if(root==NULL)
		return;
	if(max_level<level)
	{
		cout<<root->data<<" ";
		max_level = level;
	}
	left_view_of_binary_tree_recursive(root->left, level+1);
	left_view_of_binary_tree_recursive(root->right, level+1);	 
}


void left_view_of_binary_tree_iterative(Node *root)
{
	Node *curr;
	int flag=1;
	queue <Node *> s;
	s.push(root);
	s.push(NULL);
	while(s.size()>1)
	{
		curr = s.front();
		s.pop();
		if(curr==NULL)
		{
			flag=1;
			s.push(NULL);
		}
		else
		{
			if(flag==1)
				cout<<curr->data<<" ";
			if(curr->left) s.push(curr->left);
			if(curr->right) s.push(curr->right);
			flag=0;
		}
	}
}






int main()
{
//     10
//    /  \      
//   20   30
//  	 /  \
// 		40  50 
	Node *root = NULL;
	root = make_node(10);
	root->left = make_node(20);
	root->right = make_node(30);
	root->right->left = make_node(40);
	root->right->right = make_node(50);
	root->right->left->right = make_node(60);
	left_view_of_binary_tree_iterative(root);

	return 0;
}
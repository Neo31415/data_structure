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

void preorder_traversal_recursive(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder_traversal_recursive(root->left);
		preorder_traversal_recursive(root->right);
	}
}


// From GFG
void preorder_traversal_iterative(Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root;   
    while (curr != NULL || s.empty() == false) 
    {      
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            cout << curr->data <<" ";
            curr = curr->left; 
        } 
  
        curr = s.top(); 
        s.pop(); 
  
        // cout << curr->data <<" "; 
        curr = curr->right; 
  
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
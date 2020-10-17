#include<iostream>

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
	ptr->right= NULL;

}

int depth_of_tree(Node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int L = depth_of_tree(root->left);
		int R = depth_of_tree(root->right);
		return max(L,R)+1;
	}
}

int maxDepth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
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
	cout<<maxDepth(root);
	return 0;
}
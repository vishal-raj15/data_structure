#include <iostream>
#include "node.cpp"
using namespace std;

class bst

{

public:

    int key;
    bst* left;
    bst* right;

  bst* root;

	bst()
	{
	    key =key;
	    left = NULL;
	    right = NULL;
	    
	}

bst *newNode(int item) 
{ 
    bst *temp =  new bst;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

bst *insert( bst* x_node , int x)
{
    if(x_node != NULL)
    {
        if(x > x_node->key){
            x_node->right = insert(x_node->right , x);
        }
        if(x < x_node->key){
            x_node->left = insert(x_node->left , x);
        }

    }
    else{
        return newNode(x);
    }

    return x_node;

}

void inorder(bst *root)
{ 

    if (root != NULL) 
    {
        
        inorder(root->left); 
        cout<< root->key<< " ";
        inorder(root->right); 
        
    } 
}

void preorder(bst *root)
{
    if(root == NULL) return;
    cout<<root->key;
    inorder(root->left);
    inorder(root->right);
}

void postorder(bst *root)
{
    if(root == NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->key;
}

bst *min(bst * node)
{   
    if(node == NULL) exit(1);
    if(node->left = NULL)
    {
        return node;
    }
    else{

        return min(node->left);

    }
   
}


};

int main()
{
    bst *root = NULL;
bst obj;
root = obj.insert(root , 40);
obj.insert(root , 10);
obj.insert(root,60);
obj.insert(root,80);
obj.insert(root,90);
obj.insert(root,123);
obj.insert(root,43);
obj.insert(root,67);
obj.inorder(root);


    return 0;
    
}

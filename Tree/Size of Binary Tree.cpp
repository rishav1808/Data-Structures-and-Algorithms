/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
    
};

int sizeOfBT(node *root){
    if(root==NULL)
    return 0;
    int left_size=sizeOfBT(root->left);
    int right_size=sizeOfBT(root->right);
    return(left_size+right_size+1);
}

int main()
{
   node *root=new node(10);
	root->left=new node(20);
	root->right=new node(30);
	root->left->left=new node(40);
	root->left->right=new node(50);
	root->right->left=new node(60);
	root->right->right=new node(70);
	cout<<sizeOfBT(root);

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    
    node(int x){
        data=x;
        left=right=NULL;
    }
};

int maxHeightOfBT(node *root){//IMP: Counts Number of Edges and not nodes
    if(root==NULL)
    return -1;
    
    int left_size=maxHeightOfBT(root->left);
    int right_size=maxHeightOfBT(root->right);
    return(max(left_size,right_size)+1);
    
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
	
	cout<<maxHeightOfBT(root);

    return 0;
}


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


void levelOrder(node *root){
    if(root==NULL)
    return;
    
    queue<node *>q;
    q.push(root);
    
    while(!q.empty()){
        node *curr=q.front();
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
        cout<<curr->data<<" ";
        q.pop();
    }
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
	
	levelOrder(root);

    return 0;
}


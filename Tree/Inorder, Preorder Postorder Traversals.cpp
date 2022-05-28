#include <bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root){
    if(root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root==NULL)
    return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}

int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    

    return 0;
}


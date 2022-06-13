#include <bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

void iterativePostOrder(Node *root)
{
    if(root==NULL)
    return;
    stack<Node *>st1,st2;
   
    st1.push(root);
    while(!st1.empty())
    {
        Node *curr=st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left)
        st1.push(curr->left);
        if(curr->right)
        st1.push(curr->right);
        
    }
    while(!st2.empty())
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}


int main()
{
   Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	iterativePostOrder(root);

    return 0;
}


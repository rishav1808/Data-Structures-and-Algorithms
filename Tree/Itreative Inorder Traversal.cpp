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

void iterativeInorder(Node *root)
{
    if(root==NULL)
    return ;
    stack<Node *>st;
    Node *curr=root;
    while(true)
    {
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            if(st.empty())break;
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    
}


int main()
{
   Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	iterativeInorder(root);

    return 0;
}


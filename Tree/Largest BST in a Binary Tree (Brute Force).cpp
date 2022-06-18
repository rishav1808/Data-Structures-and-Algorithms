#include <bits/stdc++.h>

using namespace std;
//int count=0;
//int maxcount=-1;
struct Node{
  int data;
  Node *left;
  Node *right;
  
  Node(int x)
  {
      data=x;
      left=NULL;
      right=NULL;
  }
};

bool validateBST(Node *root, int lmax,int rmax)
{
    if(!root)
    return true;
    if(root->data < lmax || root->data > rmax)
    return false;
    
    bool left_subtree = validateBST(root->left,lmax,root->data);
    bool right_subtree = validateBST(root->right,root->data,rmax);
    
    return (left_subtree && right_subtree);
}
void inorder(Node *root,int &count)
{
    if(!root)
    return;
    inorder(root->left,count);
    count++;
    inorder(root->right,count);
    
    
}

int countNodes(Node *root)
{
    int count=0;
    inorder(root,count);
  // int maxcount= max(maxcount,count);
    //count=0;
    return count;
}

bool check1(Node *root)
{
    return validateBST(root,INT_MIN,INT_MAX);
}

int largestBST (Node *root)
{
  
    if(!root)
    return 0;
    if(validateBST(root,INT_MIN,INT_MAX))
    {
        return countNodes(root);
    }
   else
    return max(largestBST(root->left), largestBST(root->right));
    
}

int main()
{
   Node *root=new Node(20);
   root->left=new Node(15);
   root->right=new Node(40);
   root->left->left=new Node(14);
   root->left->right = new Node(18);
   root->left->left->right= new Node(17);
   root->left->right->left = new Node(10);
   root->left->right->right = new Node(19);
   root->right->left=new Node(30);
   root->right->right=new Node(60);
   root->right->right->left=new Node(50);
    
  cout<<largestBST(root);

    return 0;
}


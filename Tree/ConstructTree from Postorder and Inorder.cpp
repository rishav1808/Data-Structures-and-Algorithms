void createMapping(int in[],int n,map<int,int>&mp)
{
    for(int i=0;i<n;i++)
    mp[in[i]]=i;
}

Node * solve(int in[],int post[],int &index,int inStart,int inEnd,int n,map<int,int>&mp)
{
    if(index<0 || inStart>inEnd)
    return NULL;
    
    int element = post[index];
    index--;
    
    int position = mp[element];
    
    Node *root=new Node(element);
    
    root->right = solve(in,post,index,position+1,inEnd,n,mp);
    root->left = solve(in,post,index,inStart,position-1,n,mp);
    
    return root;
}


Node *buildTree(int in[], int post[], int n) {
   int index=n-1;
   int inStart=0,inEnd=n-1;
   map<int,int>mp;
   createMapping(in,n,mp);
   return solve(in,post,index,inStart,inEnd,n,mp);
}


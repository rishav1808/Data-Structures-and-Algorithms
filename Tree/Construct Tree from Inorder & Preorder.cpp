class Solution{
    public:
    
    /*int fun1(int in[],int &element ,int n){
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            return i;
        }
        return -1;
    }*/
    
    void createMapping(int in[],map<int,int>&mp,int n)
    {
        for(int i=0;i<n;i++)
        mp[in[i]]=i;
    }
    
    Node * solve(int in[],int pre[],int &index,int inStart,int inEnd,int n,map<int,int>&mp)
    {
        if(index<0 || inStart>inEnd)
        {
            return NULL;
        }
        
        int element = pre[index];
        index++;
        //int position=fun1(in,element,n);
        int position=mp[element];
        
        Node *root = new Node(element);
       
        
        
        root->left=solve(in,pre,index,inStart,position-1,n,mp);
        root->right=solve(in,pre,index,position+1,inEnd,n,mp);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        int inStart=0, inEnd=n-1;
        map<int,int>mp;
        createMapping(in,mp,n);
        return solve(in,pre,index,inStart,inEnd,n,mp);
        
        
    }
};

void leftTraversal(Node *root,vector<int>&ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL))
        return;
        
       ans.push_back(root->data);
        if(root->left)
        {
             
               leftTraversal(root->left,ans);
        }
      
        else{
            leftTraversal(root->right,ans);
        }
    }  
    void addLeaves(Node *root,vector<int>&ans){
        if(root==NULL)
        return;
        addLeaves(root->left,ans);
        if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
        addLeaves(root->right,ans);
    }
    
    void rightTraversal(Node *root,vector<int>&ans){
        if((root==NULL)  || (root->left==NULL && root->right==NULL))
        return;
        if(root->right){
             rightTraversal(root->right,ans);
             
        }
       
        else{
            rightTraversal(root->left,ans);
            
        }
        ans.push_back(root->data);
    }
        
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        
        if(root==NULL)
        return ans;
        
       ans.push_back(root->data);
        //Left Traversal
        leftTraversal(root->left,ans);
        
        //Leaves
        addLeaves(root->left,ans);
        addLeaves(root->right,ans);
        //Right Traversal
        rightTraversal(root->right,ans);
        return ans;
    }
};

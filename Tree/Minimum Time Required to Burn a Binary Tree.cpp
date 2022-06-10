class Solution {
  public:
  
  Node * createMapping(Node *root,int target,map<Node *,Node *>&nodeToParent)
  {
      queue<Node *>q;
      q.push(root);
      nodeToParent[root]=NULL;
    Node *res;
      while(!q.empty())
      {
          Node *curr=q.front();
          q.pop();
          if(curr->data==target)
          res=curr;
          
          if(curr->left)
          {
              nodeToParent[curr->left]=curr;
              q.push(curr->left);
          }
          if(curr->right)
          {
              nodeToParent[curr->right]=curr;
              q.push(curr->right);
          }
          
      }
      return res;
  }
    
    int burnTree(Node *target,map<Node *,Node *>&nodeToParent)
    {
        int Time=0;
        map<Node*,bool>visited;
        queue<Node *>ele;
        ele.push(target);
        visited[target]=1;
        
        while(!ele.empty())
        {
            bool flag=0;
            int size=ele.size();
            for(int i=0;i<size;i++)
            {
              Node *curr=ele.front();
                ele.pop();
            
            if(curr->left && visited[curr->left]!=1)
            {
               ele.push(curr->left);
               visited[curr->left]=1;
               flag=1;
            }
             if(curr->right && visited[curr->right]!=1)
            {
               ele.push(curr->right);
               visited[curr->right]=1;
               flag=1;
            }
            
            if( nodeToParent[curr] && visited[nodeToParent[curr]]!=1)
            {
                ele.push(nodeToParent[curr]);
                visited[nodeToParent[curr]]=1;
                flag=1;
            }  
        }
        if(flag==1)
        Time++;
        
            
        }
        return Time;
        
    }
    
    
    int minTime(Node* root, int target) 
    {
        map<Node *,Node *>nodeToParent;
        Node *res=createMapping(root,target,nodeToParent);
        return burnTree(res,nodeToParent);
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends

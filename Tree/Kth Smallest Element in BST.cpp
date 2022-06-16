class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0,ans;
        TreeNode *curr=root;
        while(curr!=NULL){
            
            if(curr->left==NULL)
            {
               // ans.push_back(curr->val);
                count++;
                if(count==k)
                    ans=curr->val;
                curr=curr->right;
            }
            
            else
            {
                TreeNode *prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                   // ans.push_back(curr->val);
                    count++;
                if(count==k)
                    ans=curr->val;
                    curr=curr->right;
                }
                
            }
        }
        return ans;
        
    }
};

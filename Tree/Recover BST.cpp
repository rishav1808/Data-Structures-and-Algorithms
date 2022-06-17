/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *prev=NULL;
    TreeNode *first=NULL;
    TreeNode *middle = NULL;
    TreeNode *last = NULL;
    void inorder(TreeNode *root)
    {
        if(!root)
            return ;
        inorder(root->left);
        if(prev==NULL)
        {
            prev=root;
        }
        if(prev -> val >root->val)
        {
            // 1st violation
            if(first==NULL)
            {
                 first=prev;
                 middle=root;
                
            }
            else //2nd violation
                last=root;
          
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(last==NULL)
            swap(first->val,middle->val);
        else
            swap(first->val,last->val);
        
    }
};

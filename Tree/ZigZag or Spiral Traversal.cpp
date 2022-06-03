class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>ans;
    	if(root==NULL)
    	return ans;
    	queue<Node *>q;
    	q.push(root);
    	bool leftToRight=true;
    	
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>temp(size);
    	    
    	    for(int i=0;i<size;i++)
    	    {
    	        Node *curr=q.front();
    	        q.pop();
    	        /*if(leftToRight)
    	        int index=i;
    	        else{
    	            int index=size-i-1;
    	        }*/
    	        int index=leftToRight ? i : size-i-1;
    	        temp[index]=curr->data;
    	        if(curr->left)
    	        q.push(curr->left);
    	        if(curr->right)
    	        q.push(curr->right);
    	    }
    	    for(auto x:temp)
    	    ans.push_back(x);
    	    leftToRight=!leftToRight;
    	    
    	}
    	return ans;
    }
};

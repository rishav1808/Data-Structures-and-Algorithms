
bool isPossible(int x,int y,vector<vector<bool>>&vis,vector<vector<int>>&arr,int n)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]==0 && arr[x][y]==1)
        return true;
    return false;
    
    
}



void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string>&ans,vector<vector<bool>>&vis,string path)
{
    //Edge Case
    if(arr[0][0]==0)
        return ;
    //Ans Case
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return ;
    }
    
    //Down
    if(isPossible(x+1,y,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x+1,y,arr,n,ans,vis,path+'D');
        vis[x][y]=0;
        
    }
    //Left
    if(isPossible(x,y-1,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x,y-1,arr,n,ans,vis,path+'L');
        vis[x][y]=0;
        
    }
    //Right
    if(isPossible(x,y+1,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x,y+1,arr,n,ans,vis,path+'R');
        vis[x][y]=0;
        
    }
    //Up
    if(isPossible(x-1,y,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x-1,y,arr,n,ans,vis,path+'U');
        vis[x][y]=0;
        
    }
}




vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    string path = "";
    solve(0,0,arr,n,ans,visited,path);
    return ans;
    
}

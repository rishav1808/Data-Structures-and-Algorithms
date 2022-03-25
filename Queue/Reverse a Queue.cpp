queue<int> rev(queue<int> q)
{
        queue<int>ans;
        stack<int>s;
        while(q.size()!=0)
        {
           s.push(q.front());
           q.pop();
           
        }
        while(s.size()!=0)
        {
            ans.push(s.top());
            s.pop();
        }
        return ans;
       

    
    
}

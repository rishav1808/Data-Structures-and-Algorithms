long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
        long long ans=0;
    deque<int>maxi,mini;
    //int a=INT_MIN,b=INT_MAX;
   // maxi.push_back(a);
   // mini.push_back(b);
    
    for(int i=0;i<k;i++)
    {
        while(!maxi.empty() && arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans+=arr[maxi.front()]+arr[mini.front()];
    
    
    for(int i=k;i<n;i++)
    {
        //Removal
        while(!maxi.empty() && i-maxi.front()>=k)
        {
			
            maxi.pop_front();
        }
        
        
        while(!mini.empty() && i-mini.front()>=k)
        {
            
             mini.pop_front();
        }
       
        
        //Addition
       while(!maxi.empty() && arr[maxi.back()]<=arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()]>=arr[i])
            mini.pop_back();
        
        maxi.push_back(i);
        mini.push_back(i);
        //Answer Calculation
        
        ans+=arr[maxi.front()]+arr[mini.front()];
        
    }
    return ans;
    
}


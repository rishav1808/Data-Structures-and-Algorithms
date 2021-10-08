* Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/

#include <bits/stdc++.h>

using namespace std;

vector<int> findDuplicates(vector<int>&v)
{
    int index=0;
    while(index<v.size())
    {
        int correctIndex=v[index]-1;
        if(v[index]==v[correctIndex])
        {
            index++;
        }
        else
        {
            swap(v[index],v[correctIndex]);
        }
    }
    vector<int>ans;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=i+1)
        ans.push_back(v[i]);
    }
   return ans;
   
     
    
}
int main()
{
    vector<int> a={4,3,2,7,8,2,3,1};
   vector<int>ans=findDuplicates(a);
   for(int i=0;i<ans.size();i++)
   cout<<ans[i]<<" ";

    return 0;
}

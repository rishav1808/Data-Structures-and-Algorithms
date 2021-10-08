/* Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums. */

#include <bits/stdc++.h>

using namespace std;
  vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index=0;
        while(index<nums.size())
        {
            int correctIndex=nums[index]-1;
            if(nums[index]==nums[correctIndex])
            {
                index++;
            }
            else
            {
                swap(nums[index],nums[correctIndex]);
            }
}   
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums[i]-1)
                ans.push_back(i+1);
        }
        return ans;
    }
int main()
{
    vector<int>v={4,3,2,7,8,2,3,1};
    vector<int>ans=findDisappearedNumbers(v);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

    return 0;
}

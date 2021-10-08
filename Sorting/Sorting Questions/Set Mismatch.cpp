/* You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array. */

#include <bits/stdc++.h>

using namespace std;
  vector<int> findErrorNums(vector<int>& nums) {
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
            {
                ans.push_back(nums[i]);//Duplicate number is given by v[i]
                ans.push_back(i+1);//Missing number is given by i+1 {if 1 to N range is given}

            }
                
        }
        return ans;
    }
int main()
{
    vector<int>v={1,2,2,4};
    vector<int>ans=findErrorNums(v);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";

    return 0;
}


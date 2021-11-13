/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& a, int tar) {
      vector<pair<int,int>>p;//Creating a pair which will store the element and index value.Sort the elements according to value and keep their old indxes stored
    vector<int>ans;
    for(int i=0;i<a.size();i++)
    p.push_back({a[i],i});
    sort(p.begin(),p.end());
    int start=0,end=a.size()-1;
    while(start<end)
    {
        int sum=p[start].first+p[end].first;
        if(sum==tar)
        {
            ans.push_back(p[start].second);
            ans.push_back(p[end].second);
            break;
            
        }
        else if(sum>tar)
        end--;
        else if(sum<tar)
        start++;
    }
    return ans;
    }


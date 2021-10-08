/* Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/
//Hint : Use Cyclic Sort
#include <bits/stdc++.h>

using namespace std;
 int findDuplicate(vector<int>& nums) {
        int index=0;
        while(index<nums.size())
        {
            int ci=nums[index]-1;
            if(index==ci)
                index++;
            else
            {
                if(nums[index]==nums[ci])
                    return (nums[index]);
                swap(nums[index],nums[ci]);
            }
        }
        return -1;
        
    }
int main()
{
   vector<int>v={1,3,4,2,2};
   cout<<findDuplicate(v);

    return 0;
}

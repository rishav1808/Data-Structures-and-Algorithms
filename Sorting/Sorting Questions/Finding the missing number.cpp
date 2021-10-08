/* Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.*/
//Array contain nos. from [0,N],there are N+1 total nos and N indexs present


#include <bits/stdc++.h>

using namespace std;
int missingNumber(vector<int>& nums) {
       
        int index=0;
        while(index<nums.size())
        {
            int ci=nums[index];
            if(nums[index]==nums.size())
            {
                index++;
            }
            else if(index==ci)
                index++;
                
            else
            {
                swap(nums[index],nums[ci]);
            }   
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums[i])
            {
            
                return(i);
            }
}
        return nums.size();//If all the elements present in the array are in the rang [0,N-1] then the element absent is N
    }
int main()
{
    vector<int>v={9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(v);

    return 0;
}

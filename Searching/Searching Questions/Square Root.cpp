/*
Problem Link : https://practice.geeksforgeeks.org/problems/square-root/1/?track=DSASP-Searching&batchId=154
*/

#include <iostream>
using namespace std;

int qsqroot(int tar)
{
    int start=0,end=tar,ans=-1;
    while(start<=end)
    {
         int mid=start+(end-start)/2;
         if(mid*mid<=tar)
         {
             ans=mid;
             if(mid*mid==tar)
             return ans;
             else
             start=mid+1;
         }
         else
         end=mid-1;
    }
    return ans;
    
}

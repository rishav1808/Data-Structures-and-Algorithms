/*
  153. Find Minimum in Rotated Sorted Array
  Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

*/

#include <iostream>

using namespace std;
int miniele(int *a,int n)
{
    int start=0,end=n-1,ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]<=a[n-1])//Sorted Half
        {
            ans=a[mid];//Save ans 
            end=mid-1;//Move to Unsorted half
        }
        else//Unsorted Half
        {
            start=mid+1;//Go to next element in Unsorted Half which can be minimum element
        }
         
    }
    return ans;
    
}
int main()
{
    int a[]={4,3,2,1};
    int n=4;
    cout<<miniele(a,n);

    return 0;
}

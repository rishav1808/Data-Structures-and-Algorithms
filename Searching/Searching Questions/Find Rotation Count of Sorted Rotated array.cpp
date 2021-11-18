/*
  153. Find Rotation Count in Rotated Sorted Array
  Problem Link : https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

*/

#include <iostream>

using namespace std;
int rotationCount(int *a,int n)
{
    int start=0,end=n-1,ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]<=a[n-1])//Sorted Half
        {
            ans=mid;//Save ans 
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
    cout<<rotationCount(a,n);

    return 0;
}

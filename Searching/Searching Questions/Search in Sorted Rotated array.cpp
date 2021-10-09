#include <iostream>

using namespace std;
int sortedRotated(int *a,int n,int tar)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==tar)
        return mid;
        else if(a[start]<=a[mid])
        {
            if(tar>=a[start] && tar<=a[mid])
            end=mid-1;
            else
            start=mid+1;
        }
        else if(a[mid]<=a[end])
        {
            if(tar>=a[mid] && tar<=a[end])
            start=mid+1;
            else
            end=mid-1;
        }
    }
    return -1;
}
int main()
{
    
    int a[]={4,5,6,7,0,1,2};
    int n=7;
    int tar=0;
    cout<<sortedRotated(a,n,tar);

    return 0;
}


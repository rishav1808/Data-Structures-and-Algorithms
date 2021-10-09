#include <iostream>

using namespace std;
int binarySearch(int *a,int n,int x)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==x)
        return mid;
        else if(a[mid]<x)
        start=mid+1;
        else
        end=mid-1;
    }
    return -1;
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    int n=8;
    int key=3;
    cout<<binarySearch(a,n,key);

    return 0;
}


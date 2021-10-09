#include <iostream>

using namespace std;
int mindiff(int *a,int n,int x)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==x)
        return 0;
        else if(a[mid]<x)
        {
            start=mid+1;
        }
        else if(a[mid]>x)
        end=mid-1;
    }
    return(min(abs(x-a[start]),abs(x-a[end])));
}
int main()
{
    int a[]={1,3,8,10,15};
    int n=5,x=12;
    cout<<mindiff(a,n,x);

    return 0;
}

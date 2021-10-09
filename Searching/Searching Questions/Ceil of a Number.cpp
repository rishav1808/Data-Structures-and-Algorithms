#include <iostream>

using namespace std;

int ceilNo(int *a,int n,int x)
{
    int start=0,end=n-1,mid,res=-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(a[mid]>=x)
        {
            if(a[mid]==x)
            {
                return a[mid];
            }
            
            else
            {
                res=max(a[mid],res);
                end=mid-1;
            }
            
        }
        else
            {
                start=mid+1;
                
            }
        
    }
    return res;
}

int main()
{
    int a[]={1,2,3,4,8,10,10,12,19};
    int n=9;
    int x=5;
    
    cout<<ceilNo(a,n,x);

    return 0;
}


#include <iostream>

using namespace std;

bool fun(int *a,int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0)
    return false;
    
    if(a[n-1]<=sum)
    {
        
         return  fun(a,n-1,sum)|| fun(a,n-1,sum-a[n-1]);
    }
    else
    return fun(a,n-1,sum);
}


int main()
{
    int a[]={2,3,7,8,10};
    int sum=11;
    int n=5;
    cout<<fun(a,n,sum);

    return 0;
}


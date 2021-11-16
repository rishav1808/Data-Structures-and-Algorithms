#include<iostream>
#include<cmath>
using namespace std;
int solve(int a[],int n)
{
    int res=a[0];
    for(int i=0;i<n;i++)
    {
        int curr_sum=a[i];
        int curr_max=a[i];
        for(int j=1;j<n;j++)
        {
            int index=(i+j)%n;
            curr_sum+=a[index];
            curr_max=max(curr_sum,curr_max);
        }
        res=max(curr_sum,curr_max);
    }
    
    return res;
}
int kadane(int a[],int n)
{
    int res=a[0];
    int curr=a[0];
    for(int i=1;i<n;i++)
    {
        curr=max(curr+a[i],a[i]);
        res=max(curr,res);
    }
    return res;
    

}
int max_circular(int a[],int n)
{
    int normal=kadane(a,n);
    if(normal<0)
    return normal;
    int arr_sum=a[0];
    for(int i=0;i<n;i++)
    {
        arr_sum+=a[i];
        a[i]=-a[i];
    }
    int circular=arr_sum+kadane(a,n);
    return(max(normal,circular));
}
int main()
{
    int a[]={8,-4,3,-5,4};
    cout<<max_circular(a,5);
}

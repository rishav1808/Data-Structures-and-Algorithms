#include <bits/stdc++.h>

using namespace std;
int maxiGuests(int *a,int *d,int n)
{
    sort(a,a+n);
    sort(d,d+n);
    int i=1,j=0,res=1,curr_max=1;
    while(i<n && j<n)
    {
        if(a[i]<=d[j])
        {
            curr_max++;
            i++;
            res=max(res,curr_max);
        }
        else
        {
            curr_max--;
            j++;
            res=max(res,curr_max);
            
        }
    }
    return res;
}
int main()
{
     int arr[] = { 900, 600, 700};
    int dep[] = { 1000, 800, 730};
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    cout<<maxiGuests(arr,dep, n); 

 
    return 0;
}


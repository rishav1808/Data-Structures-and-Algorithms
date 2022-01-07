/* Check if Subarray with sum 0 is present or not */
#include <bits/stdc++.h>

using namespace std;
bool zeroSubarray(int *a,int n)
{
    int sum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(s.find(sum)!=s.end())
        return true;
        if(sum==0)
        return true;
        s.insert(sum);
    }
    return false;
}
int main()
{
     int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << zeroSubarray(arr, n);

    return 0;
}

/* Check if Subarray with given sum is present or not */
#include <bits/stdc++.h>

using namespace std;
bool solve(int *a,int n,int sum)
{
    int prefix_sum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        if(s.find(prefix_sum-sum)!=s.end())
        return true;
        if(prefix_sum==sum)
        return true;
        s.insert(prefix_sum);
    }
    return false;
}
int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum=22;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << solve(arr, n, sum);

    return 0;
}

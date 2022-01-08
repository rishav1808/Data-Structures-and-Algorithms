/* Longest Subarray with equal number of 0s and 1s */
#include <bits/stdc++.h>

using namespace std;
int longest0s1s(int *a,int n)// Naive Method Time :O(N^2) Space: O(1) 
{
    int res=0;
    for(int i=0;i<n;i++)
    {int zero=0,one=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]==0)
            zero++;
            else
            one++;
            if(zero==one)
            {
                res=max(res,zero+one);
            }
        }
    }
    return res;
}
int solve(int *a,int n)//Efficient Method   Time: O(N) Space: O(N)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        a[i]=-1;
    }
    int cur_len=0,max_len=0;
    int prefix_sum=0;
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        if(prefix_sum==0)
        cur_len=i+1;
        else if(map.find(prefix_sum)!=map.end())
        {
            cur_len=i-map[prefix_sum];
        }
        else if(map.find(prefix_sum)==map.end())
        {
            map[prefix_sum]=i;
        }
        max_len=max(max_len,cur_len);
    }
    return max_len;
}
int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout <<solve(arr, n);

    return 0;
}

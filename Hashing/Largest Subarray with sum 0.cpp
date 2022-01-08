/* Problem Link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1# */
#include <bits/stdc++.h>

using namespace std;
int zeroLength(int *a,int n)
{
    int maxi=0,length=0;
    int prefix_sum=0;
    unordered_map<int,int>map;// Prefix_sum(small s):Starting Position of subarray
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        if(prefix_sum==0)
        {
            length=i+1;
        }
        else if(map.find(prefix_sum)!=map.end())//S==s or prefix_sum is found in hashMap
        {
            length=i-map[prefix_sum];
        }
        else if(map.find(prefix_sum)==map.end())
        {
             map[prefix_sum]=i;
        }
       
        maxi=max(maxi,length);
    }
    return maxi;
}
int main()
{
    int a[]={1,-1,3,2,-2,-8,1,7,10,23};
    int n=10;
    cout<<zeroLength(a,n);

    return 0;
}

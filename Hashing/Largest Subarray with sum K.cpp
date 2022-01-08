/* Largest Subarray with sum K */
#include <bits/stdc++.h>

using namespace std;
int subarrayLength(int *a,int n,int k)
{
    int maxi=0,length=0;
    int prefix_sum=0;
    unordered_map<int,int>map;// Prefix_sum(small s):Starting Position of subarray
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        if(prefix_sum==k)
        {
            length=i+1;
        }
        else if(map.find(prefix_sum-k)!=map.end())//S-k==s or prefix_sum is found in hashMap
        {
            length=i-map[prefix_sum-k];//We don't update the new positon of map element in order to find
                                    //largest subarray
        }
        else if(map.find(prefix_sum-k)==map.end())
        {
             map[prefix_sum]=i;
        }
       
        maxi=max(maxi,length);
        
    }
    return maxi;
}
int main()
{
    int a[]={3,1,0,1,8,2,3,6};
    int n=8;
    int k=5;
    cout<<subarrayLength(a,n,k);

    return 0;
}

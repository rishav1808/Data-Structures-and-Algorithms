#include <bits/stdc++.h>

using namespace std;
void bucketSort(int *a,int n,int k)
{
    int maxi=a[0];
    for(int i=1;i<n;i++)
    maxi=max(maxi,a[i]);
    maxi++;
    vector<int>bucket[k];
    for(int i=0;i<n;i++)
    {
        int bucket_index=(a[i]*k)/maxi;//deciding the element goes in which bucket
        bucket[bucket_index].push_back(a[i]);//after deciding the bucket, putting that element at the end of that bucket
    }
    //Sorting the buckets
    for(int i=0;i<k;i++)
    sort(bucket[i].begin(),bucket[i].end());//sorting the ith bucket{Sorting all buckets one by one}
    //Joining the buckets
    int index=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<bucket[i].size();j++)
        {
            a[index]=bucket[i][j];
            index++;
        }
        
        
        
    }
}
int main()
{
    int a[]={30,40,10,80,5,12,70};
    int n=7,k=4;
    bucketSort(a,n,k);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}

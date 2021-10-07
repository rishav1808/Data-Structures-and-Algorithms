#include <bits/stdc++.h>

using namespace std;
//In Insertion Sort we assume that the array is divided into two halfs-> Sorted subarray(on left side)and Unsorted Subarray(on right side)
void InsertionSort(int *a,int n)
{
    for(int i=1;i<n;i++)//Used to Traverse the unsorted subarray
    {
        int hole=i;//Notes the index which is to be sorted
        for(int j=i-1;j>=0;j--)//Used to traverse the sorted subarray{sorted half}
        {
            if(a[j]>a[hole])//If the current unsorted ele<any ele of sorted half
            {
                swap(a[j],a[hole]);//then swap it to where it belongs
                hole=j;//Now for further checking of the same update the value of hole
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int a[]={10,5,8,20,2,18};
    int b[]={6,5,3,7,2,1};
    int n=6;
    InsertionSort(b,n);
    return 0;
}


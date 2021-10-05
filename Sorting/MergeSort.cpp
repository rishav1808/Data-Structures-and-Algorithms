#include <bits/stdc++.h>

using namespace std;
void merge(int *a,int *l,int *r,int left,int right)
{
    int i=0,j=0,k=0;
    while(i<left && j<right)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<left)
    {
        a[k]=l[i];
        i++;k++;
    }
    while(j<right)
    {
        a[k]=r[j];
        k++;j++;
    }
}
void mergeSort(int *a,int n)
{
    if(n<2)
    return;
    int mid=(n/2);
    int left[mid],right[n-mid];
    for(int i=0;i<mid;i++)
    left[i]=a[i];
    for(int j=mid;j<n;j++)
    right[j-mid]=a[j];
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(a,left,right,mid,n-mid);
}
int main()
{
    int a[]={2,4,1,6,8,5,3,7};
    int n=8;
    mergeSort(a,n);
    for(auto it:a)
    cout<<it<<" ";

    return 0;
}

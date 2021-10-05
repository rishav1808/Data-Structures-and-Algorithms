//Count Inversions
#include <bits/stdc++.h>

using namespace std;

int merge(int *a,int *l,int *r,int left,int right)
{
    int i=0,j=0,k=0,count=0;
    while(i<left && j<right)
    {
        if(l[i]<r[j])
        {
            
            a[k]=l[i];
            i++;
        }
        else
        {
            count+=(left-i);
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
    return count;
}

int mergeSort(int *a,int n)
{
    int count=0;
    if(n<2)
    return 0;
    int mid=(n/2);
    int left[mid],right[n-mid];
    for(int i=0;i<mid;i++)
    left[i]=a[i];
    for(int j=mid;j<n;j++)
    right[j-mid]=a[j];
    count+=mergeSort(left,mid);
    count+=mergeSort(right,n-mid);
    count+=merge(a,left,right,mid,n-mid);
   return count;
}
int main()
{
    int a[]={2,4,1,6,8,5,3,7};
    int n=8;
    cout<<mergeSort(a,n)<<endl;
    for(auto it:a)
    cout<<it<<" ";

    return 0;
}

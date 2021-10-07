#include <bits/stdc++.h>

using namespace std;
void SelectionSort(int *a,int n)
{
    
    for(int i=0;i<n-1;i++)//1st loop signifies the no. of loops to be run
    { int mini=i;//index of minimum element
        for(int j=i+1;j<n;j++)//Traversing rest of the array 
        {
            if(a[mini]>a[j])//If we find an ele is rest of the array which is smaller than minimum ele then update mi
            mini=j;//update mini index
            
        }
        swap(a[mini],a[i]);//swap a[mini] with the assumed mini
        
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main()
{
    int a[]={10,5,8,20,2,18};
    int b[]={6,5,3,7,2,1};
    int n=6;
    SelectionSort(a,n);
    return 0;
}


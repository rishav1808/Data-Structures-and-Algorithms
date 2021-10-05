//Union of 2 Sorted Arrays
#include <bits/stdc++.h>

using namespace std;
void unionArray(int *a,int *b,int m,int n)
{
    int i=0,j=0;//Iterators through the two arrays
    while(i<m && j<n)//Run in limits 
    {
        if(i>0 && a[i]==a[i-1])//Avoiding Duplicates
        {
            i++;
            continue;
        }
        if(j>0 && b[j]==b[j-1])//Avoiding Duplicates
        {
            j++;
            continue;
        }
        if(a[i]>b[j])//Output must be in Sorted order so smaller element is printed first
        {
            cout<<b[j]<<" ";
            j++;
        }
        else if(a[i]<b[j])
        {
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;j++;
        }
    }
    
    while(i<m){if(i==0||a[i]!=a[i-1])cout<<a[i]<<" ";i++;}//B[] has finished already
        while(j<n){if(j==0||b[j]!=b[j-1])cout<<b[j]<<" ";j++;}//A[] has finished already
}
int main()
{
        int a[]={2,3,3,3,4,4};
        int b[]={4,4};
        int m=6,n=2;
        unionArray(a,b,m,n);

    return 0;
}

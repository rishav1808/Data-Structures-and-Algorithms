
#include <bits/stdc++.h>

using namespace std;
void transpose(int **arr,int n)
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        swap(arr[i][j],arr[j][i]);
    }
    
    
}
void print(int **arr,int m)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        cout<<arr[i][j]<<" ";
    }
    
}
int main()
{
    int m,n;
    cout<<"Enter Number of Rows: ";
    cin>>m;
    cout<<"Enter Number of Columns: ";
    cin>>n;
    int **arr;
    arr=new int *[m];
    for(int i=0;i<m;i++)
    arr[i]=new int[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        arr[i][j]=i+j;
        
    }
    transpose(arr,n);
    print(arr,n);
    
    

    return 0;
}

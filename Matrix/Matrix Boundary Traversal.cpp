/* Matrix Boundary Traversal */
#include <iostream>

using namespace std;
void print(int **arr,int m,int n)
{
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[0][i]<<" ";
        }
       
    }
    else if(n==1)
    {
        for(int i=0;i<m;i++)
        cout<<arr[i][0]<<" ";
    }
    else
    {
        for(int j=0;j<n;j++)
        cout<<arr[0][j]<<" ";
        for(int i=1;i<m;i++)
        cout<<arr[i][n-1]<<" ";
        for(int j=n-2;j>=0;j--)
        cout<<arr[m-1][j]<<" ";
        for(int i=m-2;i>=1;i--)
        cout<<arr[i][0]<<" ";
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
    print(arr,m,n);

    return 0;
}


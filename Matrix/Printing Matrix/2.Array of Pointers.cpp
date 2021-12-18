#include <iostream>
/* Calling Matrix as function Argument using Array of Pointers */
using namespace std;
void print(int *arr[],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
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
    int *arr[m];
    
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

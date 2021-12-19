#include <iostream>

using namespace std;
void print(int **a,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void spiralMatrix(int **a,int m,int n)
{
    int top=0,right=n-1,bottom=m-1,left=0;
    while(top<=bottom && left<=right)
    {
        for(int j=left;j<=right;j++)
        cout<<a[top][j]<<" ";
        top++;
        for(int i=top;i<=bottom;i++)
        cout<<a[i][right]<<" ";
        right--;
        if(top<=bottom)
        {
            for(int j=right;j>=left;j--)
            cout<<a[bottom][j]<<" ";
            bottom--;
        }
        if(left<=right)
        {
           for(int i=bottom;i>=top;i--)
            cout<<a[i][left]<<" ";
            left++; 
        }
        
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number of Rows: ";
    cin>>m;
    cout<<"Enter the number of Columns: ";
    cin>>n;
    int **a;
    a=new int *[m];
    for(int i=0;i<m;i++)
    a[i]=new int [n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }
    spiralMatrix(a,m,n);
    

    return 0;
}

/* Problem Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1 */

#include <iostream>

using namespace std;
const int n=4;
void print(int a[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}
void fun(int a[n][n])
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        cout<<a[j][i]<<" ";
        cout<<endl;
        
    }
}
int main()
{
   
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    print(arr);
    cout<<endl;
    fun(arr);


    return 0;
}

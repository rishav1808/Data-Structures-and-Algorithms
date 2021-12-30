/* Problem: Rotate a Matrix by 90degree in Clockwise direction */
#include <bits/stdc++.h>

using namespace std;
void rotate90cw(vector<vector<int>>matrix)
{
    for(int i=0;i<matrix.size();i++)//Finding Transpose
    {
        for(int j=i+1;j<matrix[i].size();j++)
        swap(matrix[i][j],matrix[j][i]);
    }
    for(int i=0;i<matrix.size();i++)
    {
        int low=0,high=matrix.size()-1;//Inverting each individual Row
        while(low<high)
        {
            swap(matrix[i][low],matrix[i][high]);
            low++;
            high--;
        }
    }
    for(int i=0;i<matrix.size();i++)//Printing Matrix
    {
        for(int j=0;j<matrix[i].size();j++)
        cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
   vector<vector<int>>ans;
   int m,n;
   cout<<"Enter number of Rows: ";
   cin>>m;
   cout<<"Enter number of Columns: ";
   cin>>n;
   for(int i=0;i<m;i++)
   {
       vector<int>v;
       for(int j=0;j<n;j++)
       {
           int x;
           cin>>x;
           v.push_back(x);
       }
       ans.push_back(v);
   }
   rotate90cw(ans);


    return 0;
}

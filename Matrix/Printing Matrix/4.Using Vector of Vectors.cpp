/*  4. Using Vector of Vectors*/
#include <bits/stdc++.h>

using namespace std;
void print(vector<vector<int>> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
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
    vector<vector<int>>a;
    for(int i=0;i<m;i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++)
        v.push_back(i+j);
        a.push_back(v);
    }
    print(a);

    return 0;
}

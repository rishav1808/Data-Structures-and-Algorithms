/*  4.Using Vector of Vectors*/
#include <bits/stdc++.h>

using namespace std;

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
    

    return 0;
}

/* 3. Using Array of Vectors*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
     int m,n;
    cout<<"Enter Number of Rows: ";
    cin>>m;
    cout<<"Enter Number of Columns: ";
    cin>>n;
    vector<int>arr[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        arr[i].push_back(i+j);
        
    }
  

    return 0;
}


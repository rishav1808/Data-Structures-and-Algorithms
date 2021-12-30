#include <bits/stdc++.h>

using namespace std;
void searchin2D(vector<vector<int>>matrix,int key)
{
    int row=0,column=matrix[0].size()-1;
    while(row<=matrix.size()-1 && column>=0)
    {
        if(matrix[row][column]==key)
        {
            cout<<"Element found at ("<<row<<","<<column<<")"<<endl;
            return;
        }
        else if(matrix[row][column]<key)
        {
            row++;
        }
        else
        column--;
    }
    cout<<"Element not found"<<endl;
    return;
}
int main()
{
    vector<vector<int>>ans;
    int m,n;
    cout<<"Enter number of rows: ";
    cin>>m;
    cout<<"Enter number of columns: ";
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
    int key=39;
    searchin2D(ans,key);

    return 0;
}


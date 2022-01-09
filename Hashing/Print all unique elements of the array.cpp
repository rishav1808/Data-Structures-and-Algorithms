/* Print All unique elements of the array.If a duplicate element exsits then print it only once */
#include <bits/stdc++.h>

using namespace std;
void solve(int *a,int n)
{
     unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        map[a[i]]++;
        for(int i=0;i<n;i++)
        {
            if(map[a[i]]>=1)
            {
                cout<<a[i]<<" ";
                map[a[i]]=-1;
            }
        }
}
int main()
{
    int a[]={1,1,2,2,3,3,4,5,6,7};
    solve(a,10);

    return 0;
}


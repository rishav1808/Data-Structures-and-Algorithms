/* First Repeated Element */
#include <bits/stdc++.h>

using namespace std;
int firstRepeated(int a[], int n) {
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        map[a[i]]++;
        for(int i=0;i<n;i++)
        {
            if(map[a[i]]==1)
            map.erase(a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(map.find(a[i])!=map.end())
            return i+1;
        }
        return -1;
    }

int main()
{
    int a[]={1, 5, 3, 4, 3, 5, 6};
    int n=7;
    cout<<firstRepeated(a,n);

    return 0;
}

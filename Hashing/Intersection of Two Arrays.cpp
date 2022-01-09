/* Intersection of Two Arrays */
#include <bits/stdc++.h>

using namespace std;
void intersection(int *a,int *b,int n1,int n2)
{
    unordered_map<int,int>map;
    for(int i=0;i<n1;i++)
    map[a[i]]++;
    for(int i=0;i<n2;i++)
    {
        if(map.find(b[i])!=map.end())
        {
            cout<<b[i]<<" ";
            map.erase(b[i]);
        }
    }
}
int main()
{
    int a[]={10,15,20,5,30};
    int b[]={30,5,30,80};
    intersection(a,b,5,4);
    return 0;
}


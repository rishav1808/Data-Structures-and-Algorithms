/* Count the number of distinct elements in an window of size k */
#include <bits/stdc++.h>

using namespace std;
void solve(int *a,int n,int k)
{
    int start=0,end=0;
    unordered_map<int,int>map;
    for(end=0;end<k-1;end++)
    map[a[end]]++;//accquring the 1st k-1 elements of the 1st window
    for(start=0,end=k-1;end<n;)
    {
        map[a[end]]++;//accquire
        cout<<map.size()<<" ";//work
        if(map[a[start]]==1)//release
        {
            map.erase(a[start]);
        }
        else if(map[a[start]]>1)//release
        map[a[start]]--;
        start++;
        end++;
    }
}
int main()
{
    int a[]={10,20,20,10,30,40,10,20,40};
    int k=4;
    solve(a,9,k);

    return 0;
}

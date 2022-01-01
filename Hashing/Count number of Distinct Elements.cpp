/* Count Number of Distinct Elements */
#include <bits/stdc++.h>

using namespace std;
int countDistinct1(int *a,int n)
{
    int count=0;
   
    for(int i=0;i<n;i++)
    {
         bool x=true;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]==a[i])
            {
                x=false;
                break;
            }
        }
        if(x==true)
        count++;
    }
    return count;
}
int countDistinct2(int *a,int n)
{
    sort(a,a+n);
    if(n>0)
    {
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            count++;
        }
        return count;
    }
    else
    return 0;
}
int countDistinct3(int *a,int n)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    return s.size();
}
int main()
{
    int a[]={15,12,13,12,13,13,18};
    cout<<countDistinct3(a,7);

    return 0;
}

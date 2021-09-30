#include <bits/stdc++.h>

using namespace std;
int chocolateDistribution(int *a,int n,int m)
{
    sort(a,a+n);//sorting the array so we can get the diff as a[high]-a[low]
    int low=0,high=m-1,mini=INT_MAX,curr_min=0;//high=m-1 sets the window size=m
    while(high<n)//so high goes till the last element and not beyond that
    {curr_min=a[high]-a[low];//finding current diff
     mini=min(mini,curr_min);//comparing current diff with the minimum diff among all the subarrays
     low++;high++;//sliding the window to keep size=m
    }
    return mini;//returning minimum diff of all the pssbl subarrays
}
int main()
{

    int a[]={3,4,1,9,56,7,9,12};
    cout<<chocolateDistribution(a,8,5);

    return 0;
}


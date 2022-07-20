#include <iostream>

using namespace std;


int solve(int *a,int n,int range,int sum)
{
    if(n==0)
    return abs(range - 2*sum);
    
    return min(solve(a,n-1,range,sum+a[n-1]),solve(a,n-1,range,sum));
}

int findMin(int *a,int n)
{
    int sum=0,range=0;
    for(int i=0;i<n;i++)
    range+=a[i];
    return solve(a,n,range,sum);
}

int main()
{
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The minimum difference between two sets is "
         << findMin(arr, n);
    return 0;

    return 0;
}


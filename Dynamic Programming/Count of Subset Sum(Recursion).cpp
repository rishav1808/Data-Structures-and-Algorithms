#include <iostream>

using namespace std;


int countOfSubsetSum(int *a,int n,int sum,int count)
{
    if(n==0 && sum!=0)
    return 0;
    if(sum==0)
    {
        count++;
        return count;
    }
    if(a[n-1]<=sum)
    {
        count = countOfSubsetSum(a,n-1,sum-a[n-1],count) + countOfSubsetSum(a,n-1,sum,count);
    }
    else
    count = countOfSubsetSum(a,n-1,sum,count);
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5}, sum = 7, n=5 ;
    cout<<countOfSubsetSum(arr,n,sum,0);

    return 0;
}


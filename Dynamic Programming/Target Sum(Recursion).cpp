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
int targetSum(int *a,int n,int tar)
{
	int sumArray=0;
	for(int i=0;i<n;i++)
	sumArray+=a[i];
	int sum = (tar+sumArray)/2;
	int count =0;
	return countOfSubsetSum(a,n,sum,count);
}

int main()
{
    int arr[] = {1, 1, 1, 1,1}, n=5,tar=3 ;
    cout<<targetSum(arr,n,tar);

    return 0;
}


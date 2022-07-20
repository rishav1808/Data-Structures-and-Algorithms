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
int countMinDiffSubset(int *a,int n,int diff)
{
	int sumArray=0;
	for(int i=0;i<n;i++)
	sumArray+=a[i];
	int sum = (diff+sumArray)/2;
	int count =0;
	return countOfSubsetSum(a,n,sum,count);
}

int main()
{
    int arr[] = {1, 2, 3, 1}, n=4,diff=1 ;
    cout<<countMinDiffSubset(arr,n,diff);

    return 0;
}


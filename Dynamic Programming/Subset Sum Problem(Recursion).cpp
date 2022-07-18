#include <iostream>

using namespace std;

bool subsetSum(int *a,int n ,int sum)
{
    if(n==0 && sum!=0)
    return false;
    if(sum==0)
    return true;
    
    if(a[n-1]<=sum)
    {//condition of take
        return (subsetSum(a,n-1,sum-a[n-1]) || subsetSum(a,n-1,sum));
    }
    else
    //condition of not take
    return subsetSum(a,n-1,sum);
}


int main()
{
    int set[] = {3, 34, 4, 12, 5, 2}, sum = 99;
    cout<<subsetSum(set,6,sum);

    return 0;
}


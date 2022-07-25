#include <iostream>

using namespace std;

int fun(int *coin,int index,int n,int sum ,int count)
{
    if(sum==0)
    {
        count++;
        return count;
    }
    if(index==n)
    return 0;
    
    if(coin[index]<=sum)
    {
        count = fun(coin,index,n,sum-coin[index],count) + fun(coin,index+1,n,sum,count);
    }
    else
    count = fun(coin, index+1 , n ,sum ,count);
}


int main()
{
    int coin[]={1,2,3};
    int sum=4,n=3,index=0;
    int count =0;
    cout<<fun(coin,index,n,sum,count);

    return 0;
}


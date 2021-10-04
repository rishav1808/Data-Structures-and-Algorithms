#include <iostream>

using namespace std;
//Question is solved by Hoare's Partition method
void solve(int *a,int start,int end)
{
    int i=start,j=end;
    while(true)
    {
        while(a[i]<0)//while nos.traversed by "i" is -ve then keep traversing forward
        i++;            //if an element traversed by "i" is +ve then stop
        while(a[j]>=0) //while nos.traversed by "j" is +ve then keep traversing forward
        j--;            //if an element traversed by "j" is +ve then stop
        if(i<j)//if i and j have not overlapped then swap -ve no. with  +ve no.
        swap(a[i],a[j]);
        else if(i>=j)//if i and j have overlapped i.e. i has entered the area of +ve nos. and j has entered area of -ve nos.,stop the function
        return;
    }
}
int main()
{
    int a[]={15,-3,-2,12};
    int n=4;
    solve(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    return 0;
}


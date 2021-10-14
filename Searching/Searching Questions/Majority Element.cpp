/* Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears more than N/2 times in the array.
  */
  
 /* Moore's Voting Algorithm */
#include <iostream>

using namespace std;
int majorityElement(int *a,int size)
{
    int res=0,count=1;
    for(int i=1;i<size;i++)
    {
        if(a[i]==a[res])
        count++;
        else
        count--;
        if(count==0)
        {
            res=i;count=1;
        }
        
    }
    count=0;
    for(int i=0;i<size;i++)
    {
        if(a[res]==a[i])
        count++;
    }
    if(count<=size/2)
    return -1;
    else
    return a[res];
}
int main()
{
    int a[]={3,1,3,3,2};
    int n=5;
    cout<<majorityElement(a,n);

    return 0;
}


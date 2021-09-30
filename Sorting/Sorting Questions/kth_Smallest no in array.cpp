#include <iostream>

using namespace std;
//Lomauto partition method
int partition(int *a,int start,int end)
{
    int pivot=a[end];
    int pIndex=start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex],a[end]);
    return pIndex;
}
int kthSmallest(int *a,int n,int k)
{
    int start=0,end=n-1;
   
   while(start<=end)
   {
       int ans=partition(a,start,end);
       if(ans==k-1)//Checking if the index sorted by partition fxn is our answer
       return a[ans];
       else if(ans<k)//Similar to Binary Search Questions
       {
           start=ans+1;//if k is on right side move to right
           
       }
       else if(ans>k)
       {
           end=ans-1;//if k is on left side move to left
          
       }
       
   }
   return -1;
}
int main()
{
    int a[]={1,1,1,1,1,1,1};
	
	int n=7;int k=5;
	
	cout<<kthSmallest(a,n,k);
	
	

    return 0;
}e

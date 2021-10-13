/* Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.*/

#include <bits/stdc++.h>

using namespace std;
//Function to find the median of the two arrays when they get merged.
int median(int *a,int *b,int n,int m)
{
    if(m<n)//Considering that the first array is always smaller.If second array is smaller in size then make it the 1st array and call the function again 
    {
        return median(b,a,m,n);
    }
    
    int left=(n+m+1)/2;//The length of the left half of the finally sorted array
    int low=0,high=n;//Limits of # of elements in left half of the finally sorted array from the 1st array(smaller one)
    while(low<=high)
    {
        int mid1=low+(high-low)/2;//Partition1 on the 1st array or # of elements in left subarray from 1st array
        int mid2=left-mid1;//Partition2 on the 2nd array or # of elements in left subarray from 2nd array
        
       int l1,l2,r1,r2;
        if(mid1==0)//If no elements participate from the 1st array in the left subarray then put its representation as Minimum number possible 
        {
            l1=INT_MIN;//so that our check is passed that l1<=r2
        }
        else{
            l1=a[mid1-1];//Maximum element from the 1st array which will come in the left subarray
        }
        if(mid2==0)//If no elements participate from the 2nd array in the left subarray then put its representation as Minimum number possible 
        {
            l2=INT_MIN;//so that our check is passed that l2<=r1
        }
        else{
            l2=b[mid2-1];//Maximum element from the 2nd array which will come in the left subarray
        }
        if(mid1==n)//If no elements participate from the 1st array in the right subarray then put its representation as Maximum number possible 
        {
            r1=INT_MAX;//so that our check is passed that l2<=r1
        }
        else{
            r1=a[mid1];//Minimum element from the 1st array which will come in the right subarray
        }
        
         if(mid2==m)//If no elements participate from the 2nd array in the right subarray then put its representation as Maximum number possible 
        {
            r2=INT_MAX;//so that our check is passed that l1<=r2
        }
        else{
            r2=b[mid2];//Minimum element from the 2nd array which will come in the right subarray
        }
         
         /*int l1 = mid1 == 0 ? INT_MIN : a[mid1-1];
            int l2 = mid2 == 0 ? INT_MIN : b[mid2-1]; 
            
            int r1 = mid1 == n ? INT_MAX : a[mid1];
            int r2 = mid2 == m ? INT_MAX : b[mid2]; */
       
        
        
        //Answer's Condition
        if(l1<=r2 && l2<=r1)
        {
            int med;
            if((n+m)%2==0)//Even # of elements in the combined array
            {
                med=(max(l1,l2)+min(r1,r2))/2;//median will be average of the max ele of left subarray and min ele of the right subarray
                return med;
            }
            else
            {
                med=max(l1,l2);//in odd length combined array median would be the max ele of the left subarray
                return med;
            }
            
        }
        //Condition to move left
        else if(l1>r2)//If max ele of 1st array in the left subarray is larger than the min ele of the 2nd array in the right subarray
        high=mid1-1;//Remove the left ele from the 1st array in the left subarray and take more eles in left subarray from the 2nd array
        else if(l2>r1)//If max ele of 2nd array in the left subarray is larger than the min ele of the 1st array in the right subarray
        low=mid1+1;//Remove the right ele from the 2nd array in the left subarray and take more eles in left subarray from the 1st array
    }
    return 0;
}
int main()
{
  /* int a[]={7,12,14,15};
   int b[]={1,2,3,4,9,11};
   int n1=4,n2=6;*/
   int a[]={1,2};
   int b[]={2,3,4};
   int n1=2,n2=3;
   cout<<median(a,b,n1,n2);
    return 0;
}


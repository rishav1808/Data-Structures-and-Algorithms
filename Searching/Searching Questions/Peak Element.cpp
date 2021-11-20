/* Problem Link: https://leetcode.com/problems/find-peak-element/
*/
#include <iostream>
using namespace std;
int peakElement(int *a,int n)
{
    if(n==1)
    return a[0];
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
         if(mid!=0 && mid !=n-1)
        {
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
            {
                
                return mid;
            }
            else if(a[mid]<=a[mid-1])
            {
                
              end=mid-1;  
            }
            
            else if(a[mid]<=a[mid+1])
            {
                
                start=mid+1;
            }
            
        }
        else{
        
       
          if(mid==0)
            {
                if(a[mid]>a[mid+1])
                return mid;
                else 
                start=mid+1;
                
            }
             else if(mid==n-1)
            {
                if(a[mid]>a[mid-1])
                return mid;
                else 
                end=mid-1;
                
            }
        
    }
        
        
    }
    
    
    return -1;
}
int main()
{
     int arr[] = {1,2,1,3,5,6,4}, n = 7;
     cout<<peakElement(arr,n);

    return 0;
}


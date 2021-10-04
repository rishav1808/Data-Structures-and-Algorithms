#include <iostream>

using namespace std;
//Sort 0s 1s 2s in an array
void sort0s1s2s(int *a,int n)
{
    int low=0,mid=0,high=n-1;//[0,low-1]-->0s  [low,high]-->1s  [high+1,n-1]-->2s
    while(mid<=high)//here mid is used to traverse the array.
    {
        if(a[mid]==0)
        {
            swap(a[low],a[mid]);//Put new found 0 at a[low]=0
            low++;mid++;//Now a[low]=0 and we claim that [0,low-1]-->0s , so we should move low by one position right(low++)
                        //mid is incremented because the swapped value will be 0(value of a[mid] after swapping) and we need to move forward
        }
        else if(a[mid]==1)//whenver we encounter 1 just move forward
        mid++;
        else if(a[mid]==2)
        {
            swap(a[mid],a[high]);//when we find new 2 at a[mid],we swap a[high] with a[mid]
            high--;             //Now a[high]=2(after swapping) and we claim,[high+1,n-1]-->2s so high should be moved to left by 1
                                //We don't increment mid here as the new value of a[mid](after swapping) is unknown to us,
                                 //It can be 0/1/2 ,we don't know that so we do not increment mid here .But when we do low++ and mid++ we increment
                                 //both mid and low coz a[mid](new value after swapping) is known to us as we already passed through the old value of a[low]
                                 //as low and mid start at the same position
        }
    }
}

//Sort the array around a given Pivot value.All values less the Pivot should be at left.Elements>Pivot should be at right
//And multiple values of pivot should be kept at middle(not the exact middle)

void Three_way_partition(int *a,int n,int pivot)
{
  int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]<pivot)
        {
            swap(a[low],a[mid]);
            low++;mid++;
        }
        else if(a[mid]==pivot)
        mid++;
        else if(a[mid]>pivot)
        {
            swap(a[mid],a[high]);
            high--;
        }
    }  
}
//Given a range represented by [r_low,r_high], Sort the array such that Elements<range should be at left,Elements>range should be at right
void partion_in_range(int *a,int n,int r_low,int r_high)
{
   int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(a[mid]<r_low)
        {
            swap(a[low],a[mid]);
            low++;mid++;
        }
        else if(a[mid]>=r_low && a[mid]<=r_high)
        mid++;
        else if(a[mid]>r_high)
        {
            swap(a[mid],a[high]);
            high--;
        }
    }   
}
int main()
{
    int a[]={0,1,0,2,1,2};
     int b[] = {4, 9, 4, 3, 1, 9, 4, 3, 9, 4, 3, 1, 4};
    int c[] = {10,5,6,3,20,9,40};
    int n1=sizeof(a) / sizeof(int);
    int n2=sizeof(b) / sizeof(int);
    int n3=sizeof(c) / sizeof(int);
    int r_low=5,r_high=10;
    sort0s1s2s(a,n1);
    Three_way_partition(b,n2,4);
    partion_in_range(c,n3,r_low,r_high);
    for(int i=0;i<n1;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n2;i++)
    cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0;i<n3;i++)
    cout<<c[i]<<" ";
    

    return 0;
} 

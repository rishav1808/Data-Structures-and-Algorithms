//Quick Sort using Lomuato and Hoare's Partition 
#include <bits/stdc++.h>

using namespace std;
//Lomuato's Partition
int partition(int *a,int start,int end)//finds the partitionIndex(pIndex){element which is at its correct position}
{
    
    int pivot=a[end];//always taking pivot as the end element 
    int pIndex=start;//pIndex here rep. that the current element is greater than pivot{a[pIndex]>pivot}
    for(int i=start;i<end;i++)//checking elements from [start,end-1]
    {
        if(a[i]<=a[end])//if element<=pivot,required condition hitted
        {
            swap(a[i],a[pIndex]);//a[pIndex]>pivot && a[i]<=pivot so swapping here makes all elements<=pivot be swapped to the beginning of the array
            pIndex++;//element at new a[pIndex]>pivot
        }
    }
    swap(a[pIndex],a[end]);//here pIndex represent the only value in array which is greater than pivot.Rest all greater elements are swapped to the right of the pivot
    return pIndex;//here pIndex rep the index which is at its correct position
}
//Hoare's Partition
int hoarePartition(int *a,int start,int end)
{
    int pivot=a[start];
    int i=start+1,j=end;
    while(1)
    {
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j)
        swap(a[i],a[j]);
        else
        {
            swap(a[j],a[start]);
            return j;
        }
    }
}
void quickSort(int *a,int start,int end)
{
    if(start<end)//handling the case of single element and where (0,-1) are start and end values
    {
        int pIndex=partition(a,start,end);//Selecting a pivot and all the elements smaller than pivot is kept at [start,pIndex-1] and pIndex has the value of pivot and elements greater than pivot is kept at [pIndex+1,end]
        quickSort(a,start,pIndex-1);//sorting left half of the array
        quickSort(a,pIndex+1,end);//sorting right half of array
    }
    else
    return;//at invalid index values of start and end,return
}
int main()
{
    int a[]={7,2,1,6,8,5,3,4};
    quickSort(a,0,7);
    for(int i=0;i<7;i++)
    cout<<a[i]<<" ";


    return 0;
}

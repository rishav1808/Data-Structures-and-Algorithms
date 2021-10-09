#include <iostream>

using namespace std;
int binarySearch(int *a,int start,int end,int key)
{
    int mid=start+(end-start)/2;
    if(a[mid]==key)
    return mid;
    else if(a[mid]<key)
    return binarySearch(a,mid+1,end,key);
    else
    return binarySearch(a,start,mid-1,key);
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8};
    int key=3;
    cout<<binarySearch(a,0,7,key);

    return 0;
}


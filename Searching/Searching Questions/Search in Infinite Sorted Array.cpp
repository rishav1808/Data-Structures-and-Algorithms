void infiniteSorted(int *a,int n,int x)//Here n is infinite
{
    int start=0,end=1;
    while(a[end]>=x)
    {
        start=end;
        end=end*2;
    }
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==x)
        return mid;
        else if(a[mid]<x)
        start=mid+1;
        else if(a[mid]>x)
        end=mid-1;
    }
    return -1;
}

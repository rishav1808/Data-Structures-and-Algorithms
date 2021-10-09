void binaryInfiniteSorted(int *a,int n)//Here n is infinite
{
    int start=0,end=1;
    while(a[end]<1)
    {
        start=end;
        end=end*2;
    }
    int res=INT_MAX;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==1)
        {
        	res=min(res,mid);
        	end=mid-1;
		}
        else
        {
        	start=mid+1;
		}
    }
    return res;
}

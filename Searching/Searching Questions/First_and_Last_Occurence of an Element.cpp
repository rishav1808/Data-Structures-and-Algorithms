#include <bits/stdc++.h>

using namespace std;
void firstOccurence_and_lastOcuurence(int *a,int n,int key)
{
    int start=0,end=n-1,pos,firstpos=INT_MAX;
    //firstOccurence
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(a[mid]==key)
        {
            pos=mid;
            firstpos=min(firstpos,pos);
            end=mid-1;
        }
        else if(a[mid]<key)
        start=mid+1;
        else
        end=mid-1;
    }
    cout<<"First Occurence of "<<key<<" is: "<<firstpos<<endl;
    //lastOccurence
    start=0,end=n-1,pos=0;
    int lastpos=INT_MIN;
    while(start<=end)
    {
        int midi=start+(end-start)/2;
        if(a[midi]==key)
        {
            pos=midi;
            lastpos=max(lastpos,pos);
            start=midi+1;
        }
        else if(a[midi]<key)
        start=midi+1;
        else
        end=midi-1;
    }
    cout<<"Last Occurence of "<<key<<" is: "<<lastpos<<endl;
}
int main()
{
    int a[]={2,4,10,10,10,10,18,20};
    firstOccurence_and_lastOcuurence(a,8,10);

    return 0;
}


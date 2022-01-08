/* Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/ */
#include <bits/stdc++.h>

using namespace std;

int findLongest(int *a,int n)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);//Inserting Elements in Hash Set{unordered_set}
    }
    int cur_len,max_len=0;
    for(int i=0;i<n;i++)
    {
        cur_len=0;
        if(s.find(a[i]-1)!=s.end())//If Previous element exists 
        continue;//Then continue to the next iteration i.e. next element of the array
        else{//Previous Element is not Found
            cur_len=1;//Current Element is the minimum ele of some subsequence
            while(s.find(a[i]+1)!=s.end())//Till what point  Next element exists then
            {
                cur_len++;//Increase the length of subsequence
                a[i]++;//See if further consective elements exisit or not
            }
        }
        max_len=max(max_len,cur_len);//After each subsequence store the max length
    }
    return max_len;//return the longest-consecutive-subsequence
}
int main()
{
    int arr[] = {102,4,100,1,101,3,2};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << findLongest(arr, n);

    return 0;
}


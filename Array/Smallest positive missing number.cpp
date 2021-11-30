/* Problem Link: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/?track=DSASP-Arrays&batchId=154 */
#include<bits/stdc++.h>
using namespace std;
int missingNumber(int a[], int n) 
    { 
        int index=0;
        while(index<n)
        {
            int ci=a[index]-1;
            if(a[index]>0 && a[index]<n && a[index]!=a[ci])
            {
                swap(a[index],a[ci]);
            }
            else
            {
                index++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=a[i]-1)
            return (i+1);
        }
        return (n+1);
    } 

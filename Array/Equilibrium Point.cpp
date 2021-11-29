/* Problem Link : https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1/?track=DSASP-Arrays&batchId=154 */
#include<bits/stdc++.h>
using namespace std;
int equilibriumPoint(long long a[], int n) {
        int sum=0,l_sum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        for(int i=0;i<n;i++)
        {
            if(l_sum==sum-a[i])
            return i+1;
            l_sum+=a[i];
            sum-=a[i];
        }
        return -1;
    
        // Your code here
    }

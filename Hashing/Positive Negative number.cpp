/* Problem Link: https://practice.geeksforgeeks.org/problems/positive-negative-pair5209/1/?track=DSASP-Hashing&batchId=154# */
#include <bits/stdc++.h>

using namespace std;
vector <int> findPairs(int a[], int n) 
    {
        vector<int>v;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++)
        {
            if(map.find(-a[i])!=map.end())
            {
                v.push_back(min(a[i],-a[i]));
                v.push_back(max(a[i],-a[i]));
            }
            map[a[i]]++;
        }
        return v;
    }

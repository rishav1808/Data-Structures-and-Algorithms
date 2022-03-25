// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
 vector<long long>ans;
 queue<long long>negativeIndex;
 //Processing 1st Window
 for(long long i=0;i<K;i++)
 {
     if(A[i]<0)
     negativeIndex.push(i);
 }
 //Storing First Window's Answer
 if(negativeIndex.size()>0)
 ans.push_back(A[negativeIndex.front()]);
 else 
 ans.push_back(0);
 
 for(long long i=K;i<N;i++)
 {
     //Removal
     if( negativeIndex.size()>0 && i-negativeIndex.front()>=K)
     negativeIndex.pop();
     
     //Addition
     if(A[i]<0)
     negativeIndex.push(i);
     //Answer Storing
     if(negativeIndex.size()>0)
     ans.push_back(A[negativeIndex.front()]);
     else
     ans.push_back(0);
     
 }
 return ans;
 }

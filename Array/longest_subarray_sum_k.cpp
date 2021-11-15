#include <bits/stdc++.h>

using namespace std;
int solve(int a[],int n,int k)
{
    int i=0,j=0,sum=0,maxi=0,ws=0;
    while(j<n)
    {
        sum+=a[j];
        if(sum<k)
        j++;
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=a[i];
                i++;
                if(sum==k)
                break;
                
            }
        		
            	ws=j-i+1;
            	maxi=max(maxi,ws);
            	cout<<i<<" "<<j<<endl;
            	sum-=a[i];
            	i++;j++;
            	
			
            
            
        }
        else if(sum==k)
        {
            ws=j-i+1;
            maxi=max(maxi,ws);
            cout<<i<<" "<<j<<endl;
            sum-=a[i];
            i++;j++;
        }
    }
    return maxi;
}
int main()
{
    int a[]={4,1,1,1,2,3,5};
    cout<<solve(a,7,5);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;//Creating a DS which holds our answer
        if(intervals.size()==0)
            return ans;//If given DS has no elements then return empty vector
        sort(intervals.begin(),intervals.end());//Sort the given Vector
        vector<int>temp=intervals[0];//Store first interval value in temp
        for(auto it:intervals)// it copies the intervals of Given vector one by one
        {
            if(temp[1]>=it[0])//if temp={1,3} and it={2,6} ; here temp[1]>=it[0](3>2)
            {
                temp[1]=max(temp[1],it[1]);//merge temp and it by getting the max value for our new merged Inteval end value
}
            else
            {
                ans.push_back(temp);//If temp merges with no other Inteval then push the interval in our ans
                temp=it;//Make next Interval value as temp and keep comparing like we did above
}
}
        ans.push_back(temp);//Pushing the last Interval in our ans
        return ans;//Returing our ans Vector
        
    }
int main()
{
	vector<vector<int>>v={{1,3},{2,6},{8,10},{8,9},{9,11},{15,18},{2,4},{16,17}};
    vector<vector<int>>ans=mergeIntervals(v);
    return 0;
}


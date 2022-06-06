/*Problem Statement
You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.
The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.
Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.
*/

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{

    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;
    int n=intervals.size();
    res.push_back(intervals[0]);//push first interval
    int j=0;//for tracking intervals in res vector
    for(int i=1;i<n;i++){
        if(res[j][1] >= intervals[i][0]){ //if they are overlapping 
            res[j][1] =max(res[j][1] ,intervals[i][1]);//set last val of interval to max of both
        }
        else{//if they are notoverlapping
            res.push_back(intervals[i]); //add interval to res vector 
            j++;
        }
    }
    return res;
}

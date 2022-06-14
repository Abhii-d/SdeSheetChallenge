/*Problem Statement
You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.
*/

#include<bits/stdc++.h>
bool cmp(pair<int,int> a,pair<int,int> b){
    return (a.second) < (b.second );
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> arr;
    int n=start.size();
    for(int i=0;i<n;i++){
        arr.push_back({start[i],finish[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    int cnt = 1;
    int dead = arr[0].second;
    for(auto i : arr){
        if(dead <= i.first){
            dead = i.second;
            cnt++;
        }
    }
    return cnt;
}
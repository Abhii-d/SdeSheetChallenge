/*Problem Statement
Ninja is observing an array of ‘N’ numbers and wants to make as many unique subsets as possible. Can you help the Ninja to find all the unique subsets?
Note: Two subsets are called same if they have same set of elements.For example {3,4,1} and {1,4,3} are not unique subsets.
You are given an array ‘ARR’ having N elements. Your task is to print all unique subsets.
*/

#include<bits/stdc++.h>
void solve(int idx,vector<int> subset,vector<int>&arr,set<vector<int>>&setr,int n){
    if(n==idx){
        sort(subset.begin(),subset.end());
        setr.insert(subset);
        return;
    }
    
    //include 
    subset.push_back(arr[idx]);
    solve(idx+1,subset,arr,setr,n);
    subset.pop_back();    
    //exclude
    solve(idx+1,subset,arr,setr,n);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> setr;
    vector<int> subset;
    solve(0,subset,arr,setr,n);
    vector<vector<int>>res;
    for(auto i :setr){
        res.push_back(i);
    }
    return res;
}
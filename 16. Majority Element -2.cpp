/*Problem Statement
You are given an array/list 'ARR' of integers of length ‘N’. You are supposed to find all the elements that occur strictly more than floor(N/3) times in the given array/list.*/

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    
    vector<int> res;
    map<int,int> mp;//for countingfrequency of elements
    int n=arr.size();
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i: mp){
        if(i.second > n/3)res.push_back(i.first);
    }
    return res;

}
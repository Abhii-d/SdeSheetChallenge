/*Problem Statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.*/

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>>res;
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == s){
                vector<int> temp;
                if(arr[i] > arr[j]){
                    temp.push_back(arr[j]);
                    temp.push_back(arr[i]);
                }
                else{
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                }
                res.push_back(temp);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
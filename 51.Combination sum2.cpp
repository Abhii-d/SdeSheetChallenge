/*Problem 
You are given an array ‘Arr’ of ‘N’ positive integers. You are also given a positive integer ‘target’.
Your task is to find all unique combinations of the array ‘Arr’ whose sum is equal to ‘target’. Each number in ‘Arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.
*/

#include<bits/stdc++.h>

void find2(int idx,int n,int target,vector<int>& arr,vector<int>combination , vector<vector<int>> & res){
    if( target ==0){
        res.push_back(combination);
        return ;
    }
    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1])
            continue;
        if(arr[i] <= target){
            combination.push_back(arr[i]);
            find2(i+1,n,target-arr[i],arr,combination,res);
            combination.pop_back();
        }
        else break;
    }
}

void find(int idx,int n,int target,vector<int>& arr,vector<int>combination , set<vector<int>> & res){
    if(idx==n){
        if(target==0){
            sort(combination.begin(),combination.end());
            res.insert(combination);
        }
        return ;
    }
    if(target < 0 )return;
    
    combination.push_back(arr[idx]);
    find(idx+1,n,target-arr[idx],arr,combination,res);
    combination.pop_back();
    find(idx+1,n,target,arr,combination,res);
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>>res;
    vector<int> combi;
    find2(0,n,target,arr,combi,res);
    return res;
    
    
    /*TLE
    set<vector<int>>res;
    vector<int> combination;
//     sort(arr.begin(),arr.end());
    find(0,n,target,arr,combination,res);
    vector<vector<int>>ans;
    for(auto i:res){
        ans.push_back(i);
    }
    return ans;*/
}

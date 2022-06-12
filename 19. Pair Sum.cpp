/*Problem Statement
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.*/

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // 1st approach 
   //TC = O(N*N) sc=>O(n)
/*    vector<vector<int>>res;
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

*/
    //2nd approach 
    //TC=>O(N) sc=o(n)

    vector<vector<int>> res;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int i=0;int j=n-1;
    int sum;
    while(i < j){
        sum = arr[i]+arr[j];
        if(sum == s){
            res.push_back({arr[i],arr[j]});
            int t=j-1;
            while( i < t && arr[t]==arr[t+1]){
                res.push_back({arr[i],arr[t]});
                t--;
            }
            i++;
        }
        else if(sum > s){
           j--; 
        }
        else i++;
    }
    sort(res.begin(),res.end());
    return res;
}
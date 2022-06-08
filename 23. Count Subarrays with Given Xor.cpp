/*Problem Statement
Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.*/

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    //brute force tc-> O(N^2)
    int cnt=0;
    int n=arr.size();
    for(int i=0;i<n;i++ ){
        int sum=0;
        for(int j=i;j<n;j++){
            sum^=arr[j];
            if(sum == x)cnt++;
        }
    }
    return cnt;


//optimal solution //TC -> O(N)
    map<int,int> mp;
    int xr =0 , count = 0;
    for(int i=0;i<arr.size();i++){
        xr ^=arr[i];
        if(xr == x) count++;
        if(mp.find(xr ^ x) != mp.end()) count += mp[xr ^ x];
        mp[xr]++;
    }
    return count;
}
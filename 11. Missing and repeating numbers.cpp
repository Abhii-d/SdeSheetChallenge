/*Problem Statement
You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.
Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.
Your task is to find the missing number (M) and the repeating number (R).*/


#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    map<int,int> mp;
    for(int i=0;i<n;i++)mp[arr[i]]++;
    int missing=0;
    int repeat=0;
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()) missing=i;
        if(mp[i]==2)repeat=i;
    }
    return {missing,repeat};
}

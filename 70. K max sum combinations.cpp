/*Problem Statement
You are given two arrays/lists ‘A’ and ‘B’ of size ‘N’ each. You are also given an integer ‘K’. You have to find the ‘K’ maximum and valid sum combinations from all the possible sum combinations of the arrays/lists ‘A’ and ‘B’.
Sum combination is made by adding one element from array ‘A’ and another element from array ‘B’.*/


#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int> allPossibility;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            allPossibility.push_back(a[i]+b[j]);
        }
    }
    sort(allPossibility.begin(),allPossibility.end());
    vector<int> res;
    int m=allPossibility.size();
    int i=m-1;
    while(k--){
        res.push_back(allPossibility[i--]);
    }
    return res;
}
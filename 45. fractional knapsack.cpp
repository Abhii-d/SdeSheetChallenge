/* Problem Statement
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.*/


#include<bits/stdc++.h>
bool cmp(pair<int,int>a , pair<int,int> b){
    return a.second/(a.first*1.0) > b.second/(b.first*1.0);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);
    double res=0;
    int curw=0;
    for(int i=0;i<n;i++){
        if(curw+items[i].first <= w){
            curw += items[i].first;
            res += items[i].second;
        }
        else{
            int rem = w -curw;
            res += (items[i].second/(items[i].first*1.0))*rem;
            break;
        }
    }
    return res;
}
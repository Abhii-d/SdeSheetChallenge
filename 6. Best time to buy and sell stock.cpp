/*Problem Statement
You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.*/


#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    
    int maxprofit=0;
    int profit=0;
    int minv=prices[0];
    int n=prices.size();
    for(int i=0;i<n;i++){
        minv= min(prices[i],minv);//minimum value till i
        profit=prices[i]-minv;//get profit in minv and  current value
        maxprofit= max(maxprofit,profit);//cal max profit till i
    }
    return maxprofit;
}
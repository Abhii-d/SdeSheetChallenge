/* Problem Statement
You are given an array (ARR) of length N, consisting of integers. You have to find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning, and 0 or more integers from the end of an array
*/

#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    //kadane's alogorithm
    long long sum=0;
    long long maxSum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum = max(sum,maxSum);
        if(sum<0)sum=0;
    }
    return maxSum;
}
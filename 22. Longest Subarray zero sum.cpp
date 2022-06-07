/*Problem Statement
Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.*/


#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    unordered_map<int,int> mp;
    int maxi=0;
    int sum=0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }else{
            if(mp.find(sum)!=mp.end()){
                maxi = max(maxi, i - mp[sum]);
            }
            else
                mp[sum] =i;
        }
    }
    return maxi;

    //2nd approach
//     int n = arr.size();
//     int mx=0;
//     int sum;
//     for(int i=0;i<n-1;i++){
//         sum=arr[i];
//         if(sum==0)mx=1;
//         for(int j=i+1;j<n;j++){
//             sum+=arr[j];
//             if(sum == 0){
//                 mx=max(mx,j-i+1);
//             }
//         }
// //         cout<<sum<<endl;
//     }
//     return mx;

}
/* Problem Statement
You have been given an array/list 'ARR' consisting of 'N' integers. Your task is to find the majority element in the array. If there is no majority element present, print -1.*/

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	
    /*if(n==1)return arr[0];
    sort(arr,arr+n);
//     cout<<arr[n/2+(n%2)]<<endl;
    if(arr[0] == arr[n/2+(n%2)])return arr[0];
    if(arr[n/2-1] ==arr[n-1])return arr[n-1];
    return -1;*/
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i : mp){
        if(i.second > n/2)return i.first;
    }
    return -1;
}
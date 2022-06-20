/*Problem Statement
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.
*/


#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> res;
    sort(arr.begin(),arr.end());
    res.push_back(arr[k-1]);
    res.push_back(arr[n-k]);
    return res;
}
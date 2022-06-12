/* Problem Statement
You are given an array/list ARR consisting of N integers. Your task is to find all the distinct triplets present in the array which adds up to a given number K.
An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.
*/

#include<set>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

    set<vector <int>>ans;
    sort(arr.begin(),arr.end());
    int sum;
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(j < k){
            if(arr[i]+arr[j]+arr[k] ==K){
                vector<int> v={arr[i],arr[j],arr[k]};
                ans.insert(v);
                k--;
                j++;
            }
            else if(arr[i]+arr[j]+arr[k] > K)k--;
            else j++;
        }
    }
    vector<vector<int>> res;
    for(auto i: ans){
        res.push_back(i);
    }
    return res;
}
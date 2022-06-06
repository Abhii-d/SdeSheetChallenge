/* Problem statement: 
You have been given a permutation of ‘N’ integers. A sequence of ‘N’ integers is called a permutation if it contains all integers from 1 to ‘N’ exactly once. Your task is to rearrange the numbers and generate the lexicographically next greater permutation.*/

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n)
{
    int k;//finding index just smaller than right element
    for( k =n-2;k>=0;k--){
        if(arr[k] < arr[k+1])
            break;
    }
    if(k < 0){//if k is -ve then sort/reverse whole array
        reverse(arr.begin(),arr.end());
        return arr;
    }
    else{
        int i=n-1;//find element geater than k from right side
        for(i=n-1;i>=0;i--){
            if(arr[k] < arr[i])break;
        }
        swap(arr[k],arr[i]);//swap those numbers
        reverse(arr.begin()+k+1,arr.end());//revverse array after k+1 position
        return arr;
    }
}
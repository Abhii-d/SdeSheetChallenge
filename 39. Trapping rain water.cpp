/* Problem Statement
You have been given a long type array/list 'ARR' of size 'N'. It represents an elevation map wherein 'ARR[i]' denotes the elevation of the 'ith' bar. Print the total amount of rainwater that can be trapped in these elevations.
*/

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long  ans,mx=0;
     long long left[n],right[n];
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        left[i]=mx;
    }
    mx=arr[n-1];
    for(int i=n-1;i>=0;i--){
        mx=max(mx,arr[i]);
        right[i]=mx;
    }
    ans=0;
    for(int i=0;i<n;i++){
        ans += min(left[i],right[i]) -arr[i];
    }
    return ans;
}
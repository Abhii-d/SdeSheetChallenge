/*Problem Statement
You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers where every row is sorted in non-decreasing order. Your task is to find the overall median of the matrix i.e if all elements of the matrix are written in a single line, then you need to return the median of that linear array.
The median of a finite list of numbers is the "middle" number when those numbers are listed in order from smallest to greatest. If there is an odd number of observations, the middle one is picked. For example, consider the list of numbers [1, 3, 3, 6, 7, 8, 9]. This list contains seven numbers. The median is the fourth of them, which is 6.
*/

#include<bits/stdc++.h>
int findlessOEM(vector<vector<int>>& mat,int n,int m,int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        int s=0;
        int e=m-1;
        while(s<=e){
            int middle = s+(e-s)/2;
            if(mat[i][middle] > mid)e=middle-1;
            else s=middle+1;
        }
//         cout<<"s----?> "<<s<<endl;
        cnt+=s;
    }
    
//     cout<<"cnt--> "<<cnt<<endl;
    return cnt;
}


int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m =matrix[0].size();
    int low=1;
    int high = 10000007;
    int mid ;
    int find =((n*m)/2 )+1;
    while(low <=  high){
        mid = low +(high-low)/2;
        int count = findlessOEM(matrix,n,m ,mid);
//         if(count == find)return mid;
        if(count >= find)high =mid-1;
        else low=mid+1;
    }
    return low;
    /*
    vector<int> v;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());  
    int newn = n*m;
    if(newn&1)return v[(newn)/2];
    return (v[newn/2]+v[newn/2+1])/2;*/
}
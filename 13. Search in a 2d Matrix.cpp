/*Problem Statement
You have been given a 2-D array 'MAT' of size M x N where 'M' and 'N' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order.
Moreover, the first element of a row is greater than the last element of the previous row (if exists).
You are given an integer 'TARGET' and your task is to find if it exists in the given 'MAT' or not.*/

#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    if(n==1 && m==1){
        if(mat[0][0] ==target)return true;
        return false;
    }
    int s=0;
    int e=n*m-1;
    int mid;
    int row,col;
    while(s <=e){
        mid= s+(e-s)/2;
        row= mid/n;
        col = mid%n;
        
        if(mat[row][col] == target)return 1;
        else if(mat[row][col] > target){
            e=mid-1;
        }else
            s=mid+1;
    }
    return 0;
    
}
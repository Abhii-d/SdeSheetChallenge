/* Problem Statement
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].*/

#include <bits/stdc++.h> 
int solve(int sx,int sy,int ex,int ey,vector<vector<int>>&dp){
    if(sx > ex || sy > ey)return 0;
    if(sx==ex && ey==sy)return 1;
    if(dp[sx][sy]!=-1)return dp[sx][sy];
    else
        return dp[sx][sy] = solve(sx+1,sy,ex,ey,dp) + solve(sx,sy+1,ex,ey,dp);
    
}

int uniquePaths(int m, int n) {
//     int res=0;
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
    return solve(1,1,m,n ,dp);
}
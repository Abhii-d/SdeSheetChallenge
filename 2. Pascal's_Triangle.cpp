/*Problem Statement
You are given an integer N. Your task is to return a 2-D ArrayList containing the pascal’s triangle till the row N.
A Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows. Pascal's triangle contains the values of the binomial coefficient.
*/

#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> res(n);//for storing result
    for(int i=0;i<n;i++){
        res[i].resize(i+1);
        res[i][0]=res[i][i]=1;//make first last ele = 1;
       for(int j=1;j<i;j++){
           res[i][j] = res[i-1][j]+res[i-1][j-1];
       }
    }
    return res;
}

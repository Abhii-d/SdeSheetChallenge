/* Problem Statement
Given a 2-dimensional matrix of size ‘N’ x ‘M’, rotate the elements of the matrix clockwise.*/

#include <bits/stdc++.h> 


void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    if(n==1 || m==1)return ;
    int i=0;

    while(n-2*i>1&&m-2*i>1){

        int t=mat[i][i];

        for(int j=i+1;j<n-i;j++)

            mat[j-1][i]=mat[j][i];

        

        for(int j=i+1;j<m-i;j++)

            mat[n-1-i][j-1]=mat[n-1-i][j];

        

        for(int j=n-1-i;j>i;j--)

            mat[j][m-1-i]=mat[j-1][m-1-i];

        

        for(int j=m-1-i;j>i;j--)

            mat[i][j]=mat[i][j-1];

        

        mat[i][i+1]=t;

        

        i++;

    }

    
    
    /*int i=0;
    
//     int v=n;
//     if(!n&1) v++;
    while(i < n/2+(n%2) && i <m/2+(n%2)){
        
        int temp = mat[i][m-1];
        for(int j=m-1;j>i;j--){
            mat[i][j]=mat[i][j-1];
        }
        int t2=mat[m-1][m-1];
        for(int j=m-1;j>i+1;j--){
            mat[j][m-1] =mat[j-1][m-1];
        }
        mat[i+1][m-1] =temp;
        
        int t3=mat[n-1][i];
        for(int j=i;j<m-1;j++){
            mat[n-1][j] =mat[n-1][j+1];
        }
        mat[n-1][m-2] = t2;
//         int t4 = mat[i][i];
        for(int j=i;j<n-1;j++){
            mat[j][i]= mat[j+1][i];
        }
        mat[n-1][i] =t3;
        swap(mat[n-1][i],mat[n-2][i]);
        i++;
        m--;n--;
        
    }*/

}
/* 
Problem Statement
Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0), then all the cells of the ith row and jth column should be changed to 0.*/


#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    int rows = matrix.size(), cols = matrix[0].size();
    vector < int > dummy1(rows,-1), dummy2(cols,-1);//for storing row col no having zero as element
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }

    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dummy1[i] == 0 || dummy2[j]==0) { //make all zeros having col or row present in vectors
                matrix[i][j] = 0;
            }
        }
    }
}
/*Problem Statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

*/


bool isPossible(vector<vector<int>>& mat,int x,int y,int n){
    
    for(int i=0;i<x;i++)
    {
        if(mat[i][y]==1)
            return false;
    }
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
    {
        if(mat[i][j]==1)
            return false;
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
    {
        if(mat[i][j]==1)
            return false;
    }
    return true;    
    
    /*for(int i=0;i<col;i++){
        if(mat[row][i]==1)return false;
    }
    for(int i=0;i<row;i++){
        if(mat[i][col]==1)return false;
    }
    int i=row;
    int j=col;
    while(i>=0 && j>=0){
        if(mat[i][j]==1)return false;
         i--;
        j--;
    }
    i=row;
    j=col;
    while(j>=0 && i < n){
        if(mat[i][j]==1)return false;
        j--;i++;
    }
    i=row;j=col;
    while(i>=0 && col <n){
        if(mat[i][j]==1)return false;
        i--;
        j++;
    }
    return true;*/
}

bool nQueen(int row,int col ,vector<vector<int>> &mat,int n,vector<vector<int>>&ans){
    if(row >=n){
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                temp.push_back(mat[i][j]);
        }
        ans.push_back(temp);
        return false;
    }
    for(int i=col;i<n;i++){
        
        if(isPossible(mat,row,i,n)){
            
            mat[row][i]=1;
            if(nQueen(row+1,0,mat,n,ans))
                return true;
            mat[row][i]=0;
         }
    }
    return false;
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    vector<vector<int>> ans;
    nQueen(0,0,res,n,ans);

    
    return ans;
}
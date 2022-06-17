/*Problem Statement
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-
*/

bool isvalid(int row,int col,int matrix[9][9],int val){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==val)return false;
    }
    for(int i=0;i<9;i++){
        if(matrix[row][i]==val)return false;
    }
    int r= (row/3)*3;
    int c=(col/3)*3;
    for(int i=r;i< r+3;i++){
        for(int j=c;j<c+3;j++){
            if(matrix[i][j]==val)return false;
        }
    }
    return true;
}


bool isItSudoku(int matrix[9][9]) {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                for(int ele =1;ele<=9;ele++){
                    if(isvalid(i,j,matrix,ele)){
                        matrix[i][j]=ele;
                        if(isItSudoku(matrix))return true;
                        else matrix[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

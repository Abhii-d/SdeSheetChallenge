/*Problem Statement
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.
*/



bool solve(vector<vector<int>>& maze,int x,int y, vector<vector<int>>&visited, vector<vector<int>>&res,int n){
    if(x<0 || x>=n || y<0||  y>=n || maze[x][y]==0 || visited[x][y]==1)return false;
    if(x==n-1 && y==n-1 && maze[x][y]==1){
        visited[x][y]=1;
            vector<int> temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    temp.push_back(visited[i][j]);
//                     visited[i][j]=0;
                }
            }
            res.push_back(temp);
    }
    visited[x][y]=1;
    
    solve(maze,x+1,y,visited,res,n);
    solve(maze,x-1,y,visited,res,n);
    solve(maze,x,y+1,visited,res,n);
    solve(maze,x,y-1,visited,res,n);
    

    visited[x][y]=0;
    
}



vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<vector<int>> res;
//     if(maze[0][0]==1)
    solve(maze,0,0,visited,res,n);

    
    return res;
}
/*Problem Statement
You are given an undirected graph in the form of an adjacency matrix along with an integer M. You need to tell if you can color the vertices of the graph using at most M colors such that no two adjacent vertices are of the same color.
For Example:
If the given adjacency matrix is:
[0 1 0]
[1 0 1]
[0 1 0] and M = 3.
The given adjacency matrix tells us that 1 is connected to 2 and 2 is connected to 3. So if we color vertex 1 with 2, vertex 2 with 1, and vertex 3 with 2, it is possible to color the given graph with 2 colors: M.
*/



bool isSafe(vector<vector<int>>& mat,int idx,int color,int n){
    for(int i=0;i<n;i++){
        if(mat[idx][i]==color)return false;
    }
    return true;
}

bool solve(vector<vector<int>>& mat,int index,int m,int n){
    if(index >= n)return true;
   
    for(int i=2;i<m+2;i++){
        if(isSafe(mat,index,i,n)){
           for(int j=0;j<n;j++){
               if(mat[j][index]==1)mat[j][index]=i;
           }
            if(solve(mat,index+1,m,n))
                return true;
            else
                for(int j=0;j<n;j++){
                    if(mat[j][index]!=0)mat[j][index]=1;
                };
                
        }
        
        
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
//     vector<int> color(m+2,0);
    int n=mat.size();
    if(solve(mat,0,m,n)){
   
        return "YES";
    }
    else return "NO";
}
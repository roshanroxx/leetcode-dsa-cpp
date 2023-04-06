class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        grid[i][j]=-1;
        if(i+1<m && grid[i+1][j]==0){
            dfs(grid,i+1,j,m,n);
        }
        if(i-1>=0 && grid[i-1][j]==0){
            dfs(grid,i-1,j,m,n);
        }
        if(j+1<n && grid[i][j+1]==0){
            dfs(grid,i,j+1,m,n);
        }
        if(j-1>=0 && grid[i][j-1]==0){
            dfs(grid,i,j-1,m,n);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int m =grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                dfs(grid,i,0,m,n);
            }
            if(grid[i][n-1]==0){
                dfs(grid,i,n-1,m,n);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==0){
                dfs(grid,0,i,m,n);
            }
            if(grid[m-1][i]==0){
                dfs(grid,m-1,i,m,n);
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    cnt++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return cnt;
    }
};
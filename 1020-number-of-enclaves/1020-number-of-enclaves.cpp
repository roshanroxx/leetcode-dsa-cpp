class Solution {
  private:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>>& v,int i,int j){
        v[i][j]=1;
        int n =grid.size();
        int m = grid[0].size();
        
        if(i+1<n && grid[i+1][j]==1 && v[i+1][j]==0){
            dfs(grid,v,i+1,j);
        }
        if(i-1>=0 && grid[i-1][j]==1 && v[i-1][j]==0){
            dfs(grid,v,i-1,j);
        }
        if(j+1<m && grid[i][j+1]==1 && v[i][j+1]==0){
            dfs(grid,v,i,j+1);
        }
        if(j-1>=0 && grid[i][j-1]==1 && v[i][j-1]==0){
            dfs(grid,v,i,j-1);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> v(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j== m-1){
                    if(v[i][j]==0 && grid[i][j] ==1){
                        dfs(grid , v,i,j);
                    }
                    
                }
            }
        }
        int cnt =0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,int n,int m){
        grid[i][j]='0';
        if(i-1>=0 && grid[i-1][j]=='1')
        {
            dfs(i-1,j, grid,n,m);
        }
        if(i+1<n && grid[i+1][j]=='1')
        {
            dfs(i+1,j, grid,n,m);
        }
        if(j-1>=0 && grid[i][j-1]=='1')
        {
            dfs(i,j-1, grid,n,m);
        }
        if(j+1<m && grid[i][j+1]=='1')
        {
            dfs(i,j+1, grid,n,m);
        }
        // for(int p=-1;p<=1;p++){
        //     for(int q=-1;q<=1;q++){
        //         int row = i+p;
        //         int clm = q+j;
        //         if(row>=0 && row<n && clm>=0 && clm<m){
        //             if(grid[row][clm]=='1'){
        //                 dfs(row,clm , grid,n,m);
        //             }
        //         }
        //     }
        // }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m =grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return cnt;
    }
};
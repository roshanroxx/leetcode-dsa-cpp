class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    v[i][j] =0;
                }
            }
        }
        while(!q.empty()){
            int c = q.size();
            for(int p=0;p<c;p++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1 ){
                    grid[i-1][j] =2;
                    v[i-1][j] =min(v[i][j]+1,v[i-1][j]);
                    q.push({i-1,j});
                }
                if(i+1<n && grid[i+1][j]==1){
                    grid[i+1][j] =2;
                    v[i+1][j] =min(v[i][j]+1,v[i+1][j]);
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1] =2;
                    v[i][j-1] =min(v[i][j]+1,v[i][j-1]);
                    q.push({i,j-1});
                }
                if(j+1<m && grid[i][j+1]==1){
                    grid[i][j+1] =2;
                    v[i][j+1] =min(v[i][j]+1,v[i][j+1]);
                    q.push({i,j+1});
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                if(v[i][j]!=INT_MAX){
                    
                    maxi = max(maxi,v[i][j]);
                }
            }
        }
        return maxi;
    }
};
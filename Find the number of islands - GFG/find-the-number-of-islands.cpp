//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private: 
    
    void bfs(int i,int j,vector<vector<bool >>& vis,vector<vector<char>>& grid){
        queue<pair<int ,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int n =grid.size();
        int m = grid[0].size();
        // cout<<i<<" "<<j<<" uu ";
        while(!q.empty()){
            int row = q.front().first;
            int column = q.front().second;
            q.pop();
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                    int nebr = row+delr;
                    int nebc = column+delc;
                    if(nebr>=0 && nebr<n){
                        if(nebc>=0 && nebc<m){
                            if(grid[nebr][nebc]=='1' && vis[nebr][nebc]==0){
                                vis[nebr][nebc]=1;
                                q.push({nebr,nebc});
                            }
                        }
                    }
                }
            }
        }
        
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool >> vis(n,vector<bool>(m,0));
        
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
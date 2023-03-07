//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& v,int i,int j,vector<pair<int,int>>& k,
    int l,int p,int n,int m){
        v[l][p]= 1;
        k.push_back({l-i,p-j});
        if(p+1<m && !v[l][p+1] && grid[l][p+1]==1){
            dfs(grid,v,i,j,k,l,p+1,n,m);
        }
        if(l+1<n && !v[l+1][p] && grid[l+1][p]==1){
            dfs(grid,v,i,j,k,l+1,p,n,m);
        }
        if(p-1>=0 && !v[l][p-1] && grid[l][p-1]==1){
            dfs(grid,v,i,j,k,l,p-1,n,m);
        }
        if(l-1>=0 && !v[l-1][p] && grid[l-1][p]==1){
            dfs(grid,v,i,j,k,l-1,p,n,m);
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n= grid.size();                             
        int m = grid[0].size();
        vector<vector<bool >> v(n,vector<bool > (m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0 && grid[i][j]==1){
                    vector<pair<int,int>> k;
                    dfs(grid,v,i,j,k,i,j,n,m);
                    s.insert(k);
                    // for(auto x:k){
                    //     cout<<x.first<<"  "<<x.second<<" i ";
                    // }
                    // cout<<endl;
                    k.clear();
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mem(int i,int j1,int j2,int n, int m, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return -1e8;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int sum=0;
        if(j1==j2){
            sum+=grid[i][j1];
        }
        else{
            sum+=grid[i][j1]+grid[i][j2];
        }
        int k=0;
        for(int p=-1;p<=1;p++){
            for(int q=-1;q<=1;q++){
                k = max(k,mem(i+1,j1+p,j2+q,n,m,grid,dp));
            }
        }
        return dp[i][j1][j2]=sum+k;
        // if(i1==i2 && j1==j2){
        //     sum1+=grid[i1][j1];
        // }
        // else{
        //   sum1+=grid[i1][j1];
        //   sum2+=grid[i2][j2]
        // }
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return mem(0,0,m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long mod = 1e9+7;
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=0;
        int i=0;
        while(i<m &&grid[0][i]!=1){
            dp[0][i]=1;
            i++;
        }
        i=0;
        while(i<n &&grid[i][0]!=1){
            dp[i][0]=1;
            i++;
        }
        // cout<<"hvbkr";
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j] =0;
                    continue;
                }
                long long left = dp[i-1][j];
                long long up = dp[i][j-1];
                long long res = left +up;
                res = res%mod;
                dp[i][j]= (int)res;
            }
        }
        return dp[n-1][m-1];
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
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
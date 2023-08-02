//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int N, int M, vector<vector<int>>& A, int x, int y,int i,int j,vector<vector<int>>& vis){
      
        if(x==i && y==j){ 
            // vis[i][j] = /'/'
            return;
        }
        int row[] = {1,-1,0,0};
        int clm[] = {0,0,1,-1};
        int k = vis[i][j];
        for(int p=0;p<4;p++){
            int ri =i+row[p];
            int cj=j+clm[p];
            // cout<<ri<<" "<<cj<<endl;
            if(ri>=0 && ri<N && cj>=0 && cj<M && ( vis[ri][cj] > k+1) && A[ri][cj]==1){
                vis[ri][cj] = k+1;
                dfs(N,M,A,x,y,ri,cj,vis);
            }
        }
    
  }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        vector<vector<int>> vis(N,vector<int>(M,INT_MAX));
        if(A[0][0]==0) return -1;
        vis[0][0] = 0;
        dfs(N,M,A,X,Y,0,0,vis);
        if(vis[X][Y]==INT_MAX) return -1;
        return vis[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
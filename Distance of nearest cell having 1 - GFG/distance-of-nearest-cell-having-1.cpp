//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
        // void bfs(vector<vector<int>>grid,vector<vector<int>>& v,pair<int,int> p){
        //     queue<pair<int,int>> q;
        //     q.push(p);
        //     v[p.first][p.second] = 0;
        //     while
        // }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n =grid.size();
	    int m =grid[0].size();
	    vector<vector<int>> v(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                v[i][j] =0;
	                q.push({i,j});
	            }
	        }
	    }
	    int count =1 ;
	    while(!q.empty()){
	        int c= q.size();
	        for(int p=0;p<c;p++){
	            int i = q.front().first;
	            int j = q.front().second;
	            q.pop();
	           // cout<<i<<" "<<j<<endl;
	            vector<int > r = {1,-1,0,0};
	            vector<int > c = {0,0,1,-1};
	            for(int l=0;l<4;l++){
	                int row = i+r[l];
	                int clm = j+c[l];
	                if(row>=0 && clm>=0 && row<n && clm<m && v[row][clm]==INT_MAX){
	                    q.push({row,clm});
	                    v[row][clm] = min(count , v[row][clm]);
	                }
	            }
	        }
	        count++;
	    }
	    return v;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int k = image[sr][sc];
        if(k==newColor){
            return image;
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            // int k = image[i][j]
            // if(i<0 || i==n || j<0 || j==m){
            //     continue;
            // }
            if(image[i][j]==k){
                image[i][j] = newColor;
                    
            }
            else{
                continue;
            }
            if(j+1<m && image[i][j+1]==k){
                q.push({i,j+1});
                
            }
            if( j-1>=0 && image[i][j-1]==k){
                q.push({i,j-1});
                
            }
            if(i+1<n && image[i+1][j]==k){
                q.push({i+1,j});
                
            }
            if(i-1>=0 && image[i-1][j]==k){
                q.push({i-1,j});
                
            }
    
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
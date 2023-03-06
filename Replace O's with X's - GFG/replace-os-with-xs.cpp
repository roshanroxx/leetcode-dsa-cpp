//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(vector<vector<char>> mat,vector<vector<bool>>& v,int i ,int j){
        v[i][j]=1;
        if(i+1<mat.size() && v[i+1][j]==0 && mat[i+1][j]=='O'){
            dfs(mat,v,i+1,j);
        }
        if(i-1>=0 && v[i-1][j]==0 && mat[i-1][j]=='O'){
            dfs(mat,v,i-1,j);
        }
        if(j+1<mat[0].size() && v[i][j+1]==0 && mat[i][j+1]=='O'){
            dfs(mat,v,i,j+1);
        }
        if(j-1>=0 && v[i][j-1]==0 && mat[i][j-1]=='O'){
            dfs(mat,v,i,j-1);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // int n= mat.size();
        // int m= mat[0].size();
        vector<vector<bool>> v(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 || i==0 || j==m-1 || i==n-1 ){
                    if(v[i][j]==0 && mat[i][j]=='O'){
                        dfs(mat,v,i,j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && v[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
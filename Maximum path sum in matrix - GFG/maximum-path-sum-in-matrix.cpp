//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]= Matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                temp[j] = max(dp[j],temp[j]);
                if(j-1>=0){
                    temp[j] = max(dp[j-1],temp[j]);
                }
                if(j+1<n){
                    temp[j] = max(dp[j+1],temp[j]);
                }
                temp[j]+=Matrix[i][j];
            }
            dp = temp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
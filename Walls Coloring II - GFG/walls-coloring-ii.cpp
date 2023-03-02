//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    // int mini(vector<vector<int>> &costs,int n,int s,int e){
        
    // }
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n==0){return 0;}
        int k =costs[0].size();
        if(n>1 && k==1){return -1;}
        vector<vector<int>> dp(n,vector<int>(k));
        
        int mini = 0;
        int mini2 = -1;
        dp[0][0] = costs[0][0];
        for(int i=1;i<k;i++){
            dp[0][i]=costs[0][i];
            if(dp[0][i]<=dp[0][mini]){
                mini2 = mini;
                mini = i;
                // cout<<"sg";
            }
            else if(mini2!=-1 && dp[0][i]<=dp[0][mini2]){
                mini2 = i;
            }
            else if(mini2==-1) mini2 = i;
        }
        // cout<<mini<<" "<<mini2<<" ooooo ";
        
        
        
        if(n==1){return dp[0][mini];}
        
        
        for(int i=1;i<n;i++){
            int m = mini;
            int l = mini2;
            mini = 0;
            mini2 = -1;
            for(int j=0;j<k;j++){
                if(j==m){
                    dp[i][j] = costs[i][j]+dp[i-1][l];
                }
                else{
                    dp[i][j] = costs[i][j]+dp[i-1][m];
                }
                
                if(j>0)
                {
                    if(dp[i][j]<=dp[i][mini]){
                        mini2 = mini;
                        mini = j;
                    }
                    else if(mini2!=-1 && dp[i][j]<=dp[i][mini2]){
                        mini2 = j;
                    }
                    else if(mini2 == -1) mini2 = j;
                }
                    
            }
        }
        // for(auto x: dp){
        //     cout<<endl;
        //     for(auto p :x){
        //         cout<<p<<" p ";
        //     }
        // }
        return dp[n-1][mini];
    }
    // 1 5
// 5 4 9 2 1
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
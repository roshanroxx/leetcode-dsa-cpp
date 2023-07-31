//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int mod = 1e9+7;
    int bellNumber(int n)
    {
       vector<vector<int>> dp(n+1,vector<int> (n+1,0));
       
       dp[0][0] =1;
       for(int i=1;i<=n;i++){
           dp[i][0] = dp[i-1][i-1];
           for(int j=1;j<=i;j++){
               dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
           }
       }
       return dp[n][0];
    }
};


//{ Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
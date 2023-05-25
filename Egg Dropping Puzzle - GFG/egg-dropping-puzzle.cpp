//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int k, int n) 
    {
        if(k==1){
            return n;
        }
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<k+1;i++){
            dp[1][i]=1;
        }
        for(int i=0;i<=n;i++){
            dp[i][1]=i;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                dp[i][j] =INT_MAX;
                for(int x=1;x<=i;x++){
                    dp[i][j] = min(dp[i][j], 1+max(dp[x-1][j-1],dp[i-x][j]));
                }
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
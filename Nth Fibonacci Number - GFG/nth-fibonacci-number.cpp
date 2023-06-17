//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long mod = 1e9+7;
    long long int pp(long long int n , vector<long long int> &dp){
        if(n<=1){
            return dp[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=(pp(n-2,dp) + pp(n-1,dp))%mod;
    }
    long long int nthFibonacci(long long int n){
        vector<long long int>  dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[n]=pp(n,dp)%mod;
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
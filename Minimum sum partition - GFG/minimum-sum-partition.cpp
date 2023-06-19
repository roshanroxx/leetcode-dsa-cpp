//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    // int mem(int i,int sum,int arr[],vector<vector<int>> &dp){
    //     if(sum==0){
    //         return 1;
    //     }
    //     if(i<0){
    //         return 0;
    //     }
    //     if(dp[i][sum] !=-1) return dp[i][sum];
    //     int nottake = mem(i-1,sum,arr,dp);
    //     int take =0;
    //     if(arr[i]<=sum){
    //         take = mem(i-1,sum-arr[i],arr,dp);
    //     }
    //     return dp[i][sum] = take || nottake;
    // }
	int minDifference(int arr[], int n)  {
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    int s = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] =1;
        }
        for(int i=1;i<=s;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(j<arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        int d= INT_MAX;
        for(int i=0;i<=s;i++){
            if(dp[n][i]==1){
                d = min(d,sum-i*2);
            }
            // cout<<dp[n][i]<<" ";
        }
        return d;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
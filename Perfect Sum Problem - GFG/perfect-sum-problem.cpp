//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod =1e9 +7;
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        int k=1;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            if(arr[i-1]==0){
                k =2*k;
            }
            dp[i][0]=k;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j<arr[i-1]){
                    dp[i][j] = dp[i-1][j]%mod;
                }
                else{
                    dp[i][j] = ((dp[i-1][j])%mod + (dp[i-1][j-arr[i-1]])%mod)%mod;
                }
            }
        }
        // for(int i=3;i<=n;i++){
        //     for(int j=0;j<=sum;j++){
        //         cout<<dp[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][sum]%mod;
//         9 20
// 3 4 10 2 5 6 5 4 0
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
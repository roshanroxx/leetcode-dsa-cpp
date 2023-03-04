class Solution {
public:
    // int pp()
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),INT_MAX));
        dp[0][0] = triangle[0][0];
        if(n==1){return dp[0][0];}
        int mini = INT_MAX;
        int k=1; 
        for(int i=1;i<n;i++){
            k =k+1;
            mini =INT_MAX;
            for(int j =0;j<k;j++){
                if(j==k-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                    mini =min(mini,dp[i][j]);
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j] +triangle[i][j];
                    mini =min(mini,dp[i][j]);
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                    mini = min(mini,dp[i][j]);
                }   
            }
        }
        // for(auto p:dp){
        //     cout<<endl;
        //     for(auto k:p){
        //         cout<<k<<" ";
        //     }
        // }
        return mini;
    }
};
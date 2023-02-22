class Solution {
public:

    int pp(string s1,string s2,int m,int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j] =0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + int(s1[i-1]);
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        int k = pp(s1,s2,m,n);
        k = -2*k;
        int i=0;
        int j=0;
        while(m || n){
            if(m){
                k+=int(s1[m-1]);
                m = m-1;
            }
            if(n){
                k+=int(s2[n-1]);
                n = n-1;
            }
        }
        return k;
    }
};
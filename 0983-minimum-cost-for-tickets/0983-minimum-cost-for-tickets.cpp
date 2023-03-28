class Solution {
public:
    int pp(vector<int>& v,vector<int>& c,int n){
        vector<int> dp(n+1);
        dp[0] =0;
        int j=0;
        for(int i=1;i<=n;i++){
            // cout<<dp[7]<<" ";
            if(i==v[j]){
                dp[i] = INT_MAX;
                if(i-1>=0){
                    dp[i] = min(dp[i-1]+c[0],dp[i]);
                }
                if(i-7>=0){
                    dp[i] = min(dp[i-7]+c[1],dp[i]);
                }
                else{
                    dp[i] = min(dp[0]+c[1],dp[i]);
                }
                if(i-30>=0){
                    dp[i] = min(dp[i-30]+c[2],dp[i]);    
                }
                else{
                    dp[i] = min(dp[0]+c[2],dp[i]);    

                }
                // if(dp[i]==INT_MAX){
                //     dp[i] =dp[i-1];
                // }
                j++;

            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days[days.size()-1];
        return pp(days,costs,n);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        dp[0]=1;
        int k =1;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            k = max(k,dp[i]);
        }
        // for(int x:dp){
        //     cout<<x<<" ";
        // }
        return k;
    }
};
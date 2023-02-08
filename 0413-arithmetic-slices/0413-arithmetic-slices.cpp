class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        vector<int> dp(nums.size()+1);
        int sum =0;
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i] - nums[i-1]==nums[i-1]-nums[i-2]){
                if(dp[i-1]>0){
                    dp[i] = dp[i-1]+1;
                    sum+=dp[i];
                }
                else{
                    dp[i]=1;
                    sum +=1;
                }
            }
            else{
                dp[i]=0;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        int j=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(sum>=target){
                ans = min(ans,i-j+1);
                // cout<<i<<" "<<j<<" "<<sum<<" p "<<ans<<endl;
                while(sum>=target){
                    ans = min(ans,i-j+1);
                    sum-=nums[j++];
                }
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};
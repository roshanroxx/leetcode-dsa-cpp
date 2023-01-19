class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l  = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int u  = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(nums.size()>0 && l<nums.size() && nums[l]==target)
        {
            cout<<l<<"  o ";
            return {l,u-1};

        }
        return {-1,-1};
    }
};
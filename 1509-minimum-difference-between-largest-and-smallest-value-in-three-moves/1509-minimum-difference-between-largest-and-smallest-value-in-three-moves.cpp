class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3){return 0;}
        sort(nums.begin(),nums.end());
        int k = nums[nums.size() -1] - nums[3];
        k =min(k, nums[nums.size() -2] -nums[2]);
        k =min(k, nums[nums.size() -3] -nums[1]);
        k =min(k, nums[nums.size() -4] -nums[0]);


        return k;
    }
};
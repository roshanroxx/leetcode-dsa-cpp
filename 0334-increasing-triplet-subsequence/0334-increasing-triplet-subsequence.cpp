class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f=nums[0];
        int second = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>second){
                return true;
            }
            if(nums[i]>f && nums[i]<second){
                second = nums[i];
            }
            if(nums[i]<f){
                f= nums[i];
            }
        }
        return false;
    }
};
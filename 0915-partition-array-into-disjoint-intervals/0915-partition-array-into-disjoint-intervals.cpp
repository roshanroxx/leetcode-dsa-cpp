class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mini(nums.size());
        mini[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            mini[i] = min(mini[i+1],nums[i]);
        }
        int k=nums[0];
        for(int i=1;i<nums.size();i++){
            if(k<=mini[i]){
                return i;
            }
            k = max(k,nums[i]);
        }
        return 0;
    }
};
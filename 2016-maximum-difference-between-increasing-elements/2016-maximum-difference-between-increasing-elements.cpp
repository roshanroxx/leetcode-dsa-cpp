class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxd = nums[1]-nums[0];
        int min = nums[0];

        for(int i =1;i<nums.size();i++)
        {
            if(nums[i]-min > maxd)
            {
                maxd = nums[i]-min;
                continue;
            }
            if(min>nums[i])
            {
                min = nums[i];
            }
        }
        if(maxd<1)
        {
            return -1;
        }
        return maxd;
    }
};
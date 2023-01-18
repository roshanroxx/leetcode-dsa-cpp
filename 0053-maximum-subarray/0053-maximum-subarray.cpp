class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res= nums[0],curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr = curr+ nums[i];
            if(curr<0)
            {
                res = max(res,curr);
                curr = 0;
            }
            else{
                res = max(res,curr);
            }
        }
        return res;
    }
};
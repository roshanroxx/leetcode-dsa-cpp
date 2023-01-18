class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res= nums[0],curr=0;
        int sum =0;
        int min_res = nums[0],min_curr=0;
        for(int i=0;i<nums.size();i++)
        {
            curr = curr+ nums[i];
            min_curr = min_curr + nums[i];
            sum += nums[i];
            if(curr<0)
            {
                res = max(res,curr);
                curr = 0;
            }
            else{
                res = max(res,curr);
            }
            if(min_curr>0)
            {
                min_res = min(min_res,min_curr);
                min_curr = 0;

            }
            else{
                min_res = min(min_res,min_curr);
            }
        }
        cout<<min_res;
        if(sum == min_res)
        {
            return res;
        }
        return max(res,sum-min_res);
    }
};
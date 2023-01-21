class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum +=nums[i];
        }
        // cout<<sum<<" ";
        sum = abs(sum-goal);
        // cout<<sum<<" ";
        long long k = sum/limit;
        // cout<< sum% limit;
        if(sum % limit==0)
        {
            return k;
        }
        return k+1;
        
    }
};
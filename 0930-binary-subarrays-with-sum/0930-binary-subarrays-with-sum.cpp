class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int ,int> mp;
        int sum =0;
        int count =0 ;
        mp.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                count = count + mp.find(sum -goal)->second;

            }
            mp[sum]++;
        }
        return count;
    }
};
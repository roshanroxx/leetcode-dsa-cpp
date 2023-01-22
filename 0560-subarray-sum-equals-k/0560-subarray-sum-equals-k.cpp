class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int sum =0;
        int count=0;
        map.insert({0,1});
        for(int i=0;i<nums.size();i++)
        {
            sum +=nums[i];
            if(map.find(sum-k)!=map.end())
            {
                auto it = map.find(sum-k);
                count+=it->second;
            }
            // if(map.find(sum)!=map.end())
            // {
            map[sum]++;
            // }
            // else{
            //     map.insert({sum,1});
            // }

        }
        return count;
    }
};
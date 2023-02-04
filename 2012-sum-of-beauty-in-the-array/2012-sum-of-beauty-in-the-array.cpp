class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> mini;
        vector<int> maxi;
        int k=nums[0];
        for(int i=0;i<nums.size();i++){
            k = max(k,nums[i]);
            maxi.push_back(max(k,nums[i]));
        }
        k=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            k = min(k,nums[i]);
            mini.push_back(min(k,nums[i]));
        }
        reverse(mini.begin(),mini.end());
        // for(auto i :mini){
        //     cout<<i<<" ";
        // }
        k=0;
        for(int i=1;i<nums.size()-1;i++){
            if(maxi[i-1]<nums[i] && nums[i]<mini[i+1]){
                k+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1]){
                k+=1;
            }
        }
        return k;
    }
};
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long psum=0;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
        }
        long long nsum=0;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            nsum+=nums[i];
            psum-=nums[i];
            if(nsum>=psum){
                count++;
            }
        }
        return count;
    }
};
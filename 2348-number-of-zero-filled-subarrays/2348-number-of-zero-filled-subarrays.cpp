class Solution {
public:
    long long k=0;
    void pp(vector<int>& nums,vector<int>& v,int i){
        if(i==nums.size()){
            return;
        }
        if(nums[i]==0){
            k = k+ v.size();
        }
        else{
            v.clear();
        }
        pp(nums,v,i);
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                temp++;
            }
            else{
                temp=0;
            }
            ans+=temp;
        }
        return ans;
    }
};
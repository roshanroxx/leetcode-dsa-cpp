class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp.insert({0,0});
        int maxi = 0;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
            if(mp.find(sum)==mp.end()){
                mp.insert({sum,i+1});
            }
            else{
                maxi = max(maxi , i -mp.find(sum)->second+1);
            }
        }
        return maxi;
    }
};
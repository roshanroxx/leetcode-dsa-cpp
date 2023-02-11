class Solution {
public:
    vector<vector<int>> v;
    void pp(const vector<int>& nums,int l,vector<int> k){
        if(l==-1){
            v.push_back(k);
            return;
        }
        // v.push_back(k);
        // for(int i=l;i<nums.size();i++){
        pp(nums,l-1,k);
        k.push_back(nums[l]);
        pp(nums,l-1,k);
        k.pop_back();
        // }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> k;
        pp(nums,nums.size()-1,k);
        return v;
    }
};
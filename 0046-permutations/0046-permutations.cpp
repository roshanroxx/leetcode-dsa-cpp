class Solution {
public:

    // bool isSafe(unordered_set<int>& s,int n){
    //     if(s.find(n)==s.end()){
    //         return true;
    //     }
    //     return false;
    // }

    void pp(vector<vector<int>>& v,vector<int>& k,vector<int>& nums,int l,int n)
    {
        if(k.size()==n){
            v.push_back(k);
            return;
        }
        else{
            for(int i=l;i<n;i++){
                // if(isSafe(s,nums[i])){
                // }
                k.push_back(nums[i]);
                swap(nums[i],nums[l]);
                // s.insert(nums[i]);
                pp(v,k,nums,l+1,n);
                swap(nums[l],nums[i]);
                k.pop_back();
                // s.erase(nums[i]);
            }
        }  
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // unordered_set<int> s;
        vector<vector<int>> v;
        vector<int> k;
        pp(v,k,nums,0,nums.size());
        return v;
    }
};
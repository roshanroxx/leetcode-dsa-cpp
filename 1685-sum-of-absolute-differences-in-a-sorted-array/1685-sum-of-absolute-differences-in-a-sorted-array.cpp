class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        vector<int> post(nums.size()+1);
        pre[0]=0;
        post[nums.size()]=0;
        for(int i=1;i<=nums.size();i++){
            pre[i] = pre[i-1]+ nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--){
            post[i] = post[i+1]+nums[i];
        }
        // for(auto x:post){
        //     cout<<x<<"  ";
        // }
        int n= nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = post[i] -(n-(2*i))*nums[i] - pre[i];
        }
        return ans;
    }
};
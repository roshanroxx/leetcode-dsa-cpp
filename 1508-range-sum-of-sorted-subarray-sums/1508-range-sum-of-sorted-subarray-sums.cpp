class Solution {
public:

    int base = (int)1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        sum=0;
        long long k=0;
        for(auto i =left-1 ; i<right;i++){
            k +=v[i];
            k=k%base;
        }
        return k;
    }
};
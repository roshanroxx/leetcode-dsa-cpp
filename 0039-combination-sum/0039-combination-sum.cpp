class Solution {
public:
    vector<vector<int >> v;
    bool isSafe(int sum,int target){
        if(sum>target){
            return false;
        }
        return true;
    }
    void solve(vector<int>& v1,vector<int>& c,int l,int sum , int target){
        if(sum==target){
            v.push_back(v1);
            return;
        }
        if(isSafe(sum,target)){
            for(int i=l;i<c.size();i++){
                sum = sum+c[i];
                v1.push_back(c[i]);
                solve(v1,c,i,sum,target);
                v1.pop_back();
                sum = sum - c[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v1;
        solve(v1,candidates,0,0,target);
        return v;
    }
};
class Solution {
public:
    vector<vector<int>> v;
    // bool isSafe(int sum,int t){
    //     if(sum>t){return false;}
 
        
    //     return true;
    // }
    void solve(vector<int>& v1,vector<int>& c,int l,int &sum ,int& t){
        if(sum == t){
            v.push_back(v1);
            return;
        }
        if(sum<=t){
            for(int i=l;i<c.size();i++){
                if(i>l && c[i]==c[i-1]){
                    continue;
                }
                sum+=c[i];
                v1.push_back(c[i]);
                solve(v1,c,i+1,sum,t);
                v1.pop_back();
                sum-=c[i];
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v1;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        solve(v1,candidates,0,sum,target);
        return v;
    }
};
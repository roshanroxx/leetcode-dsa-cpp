class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bk, int n) {
        // sort(bk.begin(),bk.end());
        // vector<int> v(n,0);
        // for(int i=0;i<bk.size();i++){
        //     for(int j=bk[i][0];j<=bk[i][1];j++){
        //         v[j-1]+=bk[i][2];
        //     }
        // }
        // vector<int> ans;
        // for(auto x:v){
        //     if(x!=0){
        //         ans.push_back(x);            }
        // }
        // return v;
        // [[2,2,30],[2,2,45]]
        // [[2,2,35],[1,2,10]]




        vector<int> res(n);
        for (auto &v : bk) {
            res[v[0] - 1] += v[2];
            if (v[1] < n) res[v[1]] -= v[2];
        }
        for (auto i = 1; i < n; ++i) res[i] += res[i - 1];
        return res;
    }
};
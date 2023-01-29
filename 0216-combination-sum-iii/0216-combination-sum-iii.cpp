class Solution {
public:

    vector<vector<int>> pq;
    void pp(int k,int n,vector<int>& m,int l,vector<int>& v){
        if(m.size()==k && n==0){
            pq.push_back(m);
            return;
        }
        if(n<0 || l==9){return;}
        m.push_back(v[l]);
        pp(k,n-v[l],m,l+1,v);
        m.pop_back();
        pp(k,n,m,l+1,v);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v ={1,2,3,4,5,6,7,8,9};
        vector<int> m;
        pp(k,n,m,0,v);
        return pq;
    }
};
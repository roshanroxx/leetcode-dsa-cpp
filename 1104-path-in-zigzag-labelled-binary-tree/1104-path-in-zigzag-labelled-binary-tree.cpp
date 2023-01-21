class Solution {
public:
    vector<int> pathInZigZagTree(int l) {
        vector<int> v;
        v.push_back(l);
        // cout<<ceil(log2(l));
        for(int i=floor(log2(l));i>0;i--)
        {
            int k =v.back()/2;
            k = (1<<(i-1)) +(1<<i)-1-k;
            v.push_back(k); 
        }
        // v.push_back(1);
        sort(v.begin(),v.end());
        return v;
    }
};
class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> v(32,0);
        int k=0;
        int j=0,l=0;
        for(int i=0;i<c.size();i++){
            j=0;
            k = c[i];
            while(k!=0){
                if(k&1){
                    v[j]++;
                }
                k = k>>1;
                j++;
            }
        }
        return *max_element(v.begin(),v.end());
    }
};
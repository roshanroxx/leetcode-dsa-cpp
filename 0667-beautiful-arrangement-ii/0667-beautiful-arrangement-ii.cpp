class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i=1;
        int j=k+1;
        vector<int> v;
        while(i<=j){
            v.push_back(i);
            if(i<j){
                v.push_back(j);
            }
            j--;
            i++;
        }
        for(int i=k+2;i<=n;i++){
            v.push_back(i);
        }
        return v;
    }
};
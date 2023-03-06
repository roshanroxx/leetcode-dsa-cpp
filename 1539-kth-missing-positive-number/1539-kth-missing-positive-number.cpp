class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int t=1;
        // int l = lower_bound(arr.begin())
        for(int a:arr){
            if(a<=k){
                k++;
                // cout<<a<<" "<<k<<" l ";
            }
        }
        return k;
    }
};
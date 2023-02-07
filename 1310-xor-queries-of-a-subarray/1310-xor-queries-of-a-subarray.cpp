class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int xr=arr[0];
        arr[0]=0;
        for(int i=1;i<arr.size();i++){
            int t =arr[i];
            arr[i] = arr[i-1]^xr;
            xr = t;
            // cout<<arr[i]<<" ";
        }
        arr.push_back(arr[arr.size()-1]^xr);
        // cout<<arr[arr.size()-1];
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i] = arr[queries[i][0]]^arr[queries[i][1]+1];
        }
        return ans;
    }
};
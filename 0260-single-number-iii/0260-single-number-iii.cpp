class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(auto x:nums)
        {
            xr = xr^x;
        }
        int sn = __builtin_ctz(xr);
        sn = (1<<sn);
        int res=0;
        // cout<<xr<<" "<<sn<<" u ";
        for(auto x:nums)
        {
            if((x&sn)!=0)
            {
                // cout<<x<<" o ";
                res = res^x;
            }
        }
        return {res,res^xr};
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;

        for(int i=0;i<32;i++)
        {
            int count=0;
            for(auto x:nums)
            {
                count+=(x>>i)&1;
            }
            // cout<<count;
            if(count%3!=0)
            {
                xr = xr|(1<<i);
                cout<<xr<<" ";
            }
        }

        // for(auto x:nums)
        // {
        //     int k = (x>>i);
        // }
        
        return xr;
    }
};
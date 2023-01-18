class Solution {
public:
    // int table[256];
    // void initial()
    // {
    //     table[0]=0;
    //     for(int i=1;i<256;i++)
    //     {
    //         table[i]=(i&1)+table[i/2];
    //     }
    // }

    // int count(int n)
    // {
    //     int res = table[n & 0xff];
    //     n=n>>8;
    //     res = res + table[n & 0xff];
    //     n=n>>8;
    //     res = res + table[n & 0xff];
    //     n=n>>8;
    //     res = res + table[n & 0xff];
    //     return res;
    // }

    // int count(int n)
    // {
    //     int k=0;
    //     while(n>0)
    //     {
    //         if((n&1)==1)
    //         {
    //             k++;

    //         }
    //         n = n>>1;
    //     }
    //     return k;
    // }

    int totalHammingDistance(vector<int>& nums) {
        // initial();
        // unordered_map<int,int> m;
        // sort(nums.begin(),nums.end());
        int k=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
                
        //         k = k+count(nums[i]^nums[j]);
        //     }
        // }

        for(int i=0;i<32;i++)
        {
            int one =0,zero=0;
            for(auto x:nums)
            {
                if((x&(1<<i))!=0)
                {
                    one++;
                }
                else{
                    zero++;
                }
            }
            k +=one*zero;
        }
        return k;
    }
};
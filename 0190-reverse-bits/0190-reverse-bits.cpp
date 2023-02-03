class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        int d=0;
        while(n>0){
            x = x+ ((n&1)<<(31-d));
            n = n>>1;
            d++;
        }
        return x;
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        uint32_t ans = 0;
        while(i < 32){
            uint32_t bit = n & 1;

            ans =  ans | (bit<<(31-i)) ;

            n = n>>1;
            i++;
        }
        return ans;
    }
};

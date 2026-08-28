class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int y = x;

        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1
        while(y){
            int digit = y%10;
            y /= 10;
            ans = (ans * 10) + digit;

            
            if(ans > MAX/10){
                return 0;
            }
            if(ans < MIN/10){
                return 0;
            }
        }
        return ans;
    }
};

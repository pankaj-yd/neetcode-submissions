class Solution {
public:
    int reverse(int x){
        int ans = 0;
        int y = abs(x);
        while(y){
            int d = y%10;
            y /= 10;

            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && d > INT_MAX%10)){
                return 0;
            }
            if(x < 0 && ans > abs(INT_MIN/10) || (ans == abs(INT_MIN/10) && d > abs(INT_MIN%10) )){
                return 0;
            }

            ans *= 10;
            ans += d;
        }
        if(x > 0) return ans;
        return -ans;
    }
};

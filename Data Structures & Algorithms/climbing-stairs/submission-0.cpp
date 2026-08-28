class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        if(n == 0){
            return 1;
        }else if(n < 0){
            return 0;
        }

        count += climbStairs(n-1);
        count += climbStairs(n-2);

        return count;
    }
};

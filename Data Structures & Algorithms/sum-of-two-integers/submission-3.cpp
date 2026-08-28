class Solution {
public:
    int Sum(int a, int b){
        if(b == 0){
            return a;
        }

        return Sum(a^b, (a&b)<<1);
    }

    int Diff(int a, int b){
        return Sum(a, Sum(~b, 1));
    }

    int getSum(int a, int b) {
        // for Diff
        // return Diff(a, b);
        return Sum(a, b);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        } else if(n == 2){
            return max(nums[0], nums[1]);
        }

        int finalAns = 0;
        int first = 0, second = 0;
        int ans = 0;
        for(int i = n-2; i >= 0; i--){
            ans = max(nums[i] + second, first);
            second = first;
            first = ans;
        }

        finalAns = ans;

        first = 0, second = 0, ans = 0;
        for(int i = n-1; i > 0; i--){
            ans = max(nums[i] + second, first);
            second = first;
            first = ans;
        }

        return max(ans, finalAns);
    }
};

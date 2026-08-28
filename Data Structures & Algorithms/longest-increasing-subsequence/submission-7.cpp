class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if (n == 0){
            return 0;
        }

        // numVal, lenOfLIS
        vector<int> dp(n, 1);
        int ans = 1;

        for(int i = 1; i < n; i++){
            int currLen = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};

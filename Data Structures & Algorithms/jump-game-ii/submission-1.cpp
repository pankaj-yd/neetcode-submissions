class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int count = 1;
            while(count <= nums[i]){
                if(i + count >= n){
                    break;
                }
                dp[i] = min(dp[i+count], dp[i]);
                count++;
            }
            if(dp[i] != INT_MAX) dp[i]++;
        }

        return dp[0];
    }
};

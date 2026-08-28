class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        ans[0] = nums[0];
        for(int i = 1; i < n; i++) {
            ans[i] = nums[i] * ans[i-1];
        }

        int postfix = 1;
        for (int i = n-1; i > 0; i--){
            ans[i] = ans[i-1] * postfix;
            postfix *= nums[i];
        }
        ans[0] = postfix;
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lp(n, 1);
        lp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            lp[i] = nums[i] * lp[i-1];
        }

        vector<int> rp(n,1);
        rp[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            rp[i] = nums[i] * rp[i+1];
        }

        vector<int> ans(n,1);
        ans[0] = rp[1];
        ans[n-1] = lp[n-2];
        for(int i = 1; i < n-1; i++){
            ans[i] = lp[i-1] * rp[i+1];
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos = 1, neg = 1;
        int ans = nums[0];
        for(int n : nums){
            int tmp = n * pos;
            pos = max(max(tmp, neg*n), n);
            neg = min(min(tmp, neg*n), n);
            ans = max(ans, pos);
        }
        return ans;
    }
};

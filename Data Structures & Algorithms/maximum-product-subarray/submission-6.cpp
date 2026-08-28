class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma = 1, mi = 1;

        int ans = INT_MIN;
        for(int n : nums){
            int tmp = ma;
            ma = max({ma * n, mi*n, n});
            mi = min({tmp * n, mi*n, n});
            
            ans = max(ma, ans);
        }

        return ans;
    }
};

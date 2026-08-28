class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        } else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        int n = nums.size();
        vector<int> rob(n, 0);
        rob[0] = nums[0], rob[1] = max(nums[0], nums[1]);
        int ans = 0;
        for(int i = 2; i < n-1; i++){
            rob[i] = max(rob[i-1], nums[i] + rob[i-2]);
            ans = max(ans, rob[i]);
        }

        rob[0] = 0, rob[1] = nums[1];
        for(int i = 2; i < n; i++){
            rob[i] = max(rob[i-1], nums[i] + rob[i-2]);
            ans = max(ans, rob[i]);
        }
        
        return ans;

    }
};

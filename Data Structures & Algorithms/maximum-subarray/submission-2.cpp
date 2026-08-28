class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int currSum = nums[0];
        for(int i = 1; i < n; i++){
            currSum = max(nums[i], currSum + nums[i]);
            sum = max(currSum, sum);
        }
        
        return sum;
    }
};

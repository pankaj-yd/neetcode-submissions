class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int currSum = nums[0];
        for(int i = 1; i < n; i++){
            if(currSum < 0) currSum = 0;

            if(currSum + nums[i] < 0) {
                sum = max(sum, nums[i]);
                currSum = nums[i];
            } else {
                currSum += nums[i];
            }
            sum = max(currSum, sum);
        }
        
        return sum;
    }
};

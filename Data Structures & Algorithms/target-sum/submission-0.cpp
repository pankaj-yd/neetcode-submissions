class Solution {
    int calc(vector<int> &nums, int target, int i){
        if(target == 0 && i == nums.size()){
            return 1;
        } else if(i == nums.size()){
            return 0;
        }



        int pos = calc(nums, target + nums[i], i+1);
        int neg = calc(nums, target - nums[i], i+1);

        return pos + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return calc(nums, target, 0);
    }
};

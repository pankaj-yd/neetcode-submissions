class Solution {
/*
    ans = 0;
    cache -> {idx, target}
    find(nums, idx, target){
        if(idx == nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        return find(nums, idx+1, target + nums[idx]) + find(nums, idx+1, target - nums[idx]);
    }

*/


public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> sums;
        sums[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int, int> newSums;
            int num = nums[i];
            for(auto it : sums){
                int sum = it.first;
                int count = it.second;
                newSums[sum + num] += count;
                newSums[sum - num] += count;
            }
            sums = newSums;
        }
        return sums[target];
    }
};

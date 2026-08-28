class Solution {
private:
    bool partition(vector<int>& nums, int idx, int a, int b){
        if (idx == nums.size()){
            if (a == b) {
                return true;
            }
            return false;
        }

        // add in subset a
        return partition(nums, idx+1, a + nums[idx], b) || partition(nums, idx+1, a, b + nums[idx]);
    }

public:
    bool canPartition(vector<int>& nums){
        return partition(nums, 0, 0, 0);
    }
};

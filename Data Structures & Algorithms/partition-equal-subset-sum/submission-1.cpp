class Solution {
private:
    bool dfs(vector<int>& nums, int toMake, int i){
        if(toMake == 0){
            return true;
        }
        if( toMake < 0 || i == nums.size()){
            return false;
        }

        bool with = dfs(nums, toMake - nums[i], i+1);
        if(with){
            return true;
        }
        
        bool without = dfs(nums, toMake, i+1);
        if(without){
            return true;
        }

        return false;

    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 2 == 1) return false;
        int toMake = sum/2;

        return dfs(nums, toMake, 0);
    }
};

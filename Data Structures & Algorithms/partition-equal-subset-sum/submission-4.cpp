class Solution {
private:
    map<pair<int,int>, bool> cache;
    bool partition(vector<int>& nums, int idx, int diff){
        if (idx == nums.size()){
            if (diff == 0){
                cache[{idx, diff}] = true;
                return true;
            }
            cache[{idx, diff}] = false;
            return false;
        }
        auto it = cache.find({idx, diff});
        if ( it != cache.end()){
            return it->second;
        }

        // add in subset a
        bool ans = partition(nums, idx+1, diff + nums[idx]) || partition(nums, idx+1, diff - nums[idx]);
        cache[{idx, diff}] = ans;
        return ans;
    }

public:
    bool canPartition(vector<int>& nums){

        return partition(nums, 0, 0);
    }
};

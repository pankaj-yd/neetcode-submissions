class Solution {
private:
    bool check(vector<int>& nums, int i, unordered_map<int, bool> &cache){
        if(i >= nums.size()) return false;
        if(i == nums.size() - 1) return true;

        
        if(cache.find(i) != cache.end()){
            return cache[i];
        }

        int steps = nums[i];

        int count = 1;
        while(count <= steps){
            
            if(check(nums, i + count, cache)){
                cache[i] = true;
                return true;
            }
            count++;
        }
        cache[i] = false;
        return false;

    }
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> cache;
        return check(nums, 0, cache);
    }
};

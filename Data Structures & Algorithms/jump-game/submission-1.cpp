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
        int n = nums.size();
        if(n == 1) return true;
        vector<int> dp(n, -1);

        dp[n-1] = n-1;

        for(int i = n-2; i >= 0; i--){
            int steps = nums[i];
            if(i + steps >= dp[i+1]){
                dp[i] = i;
            } else {
                dp[i] = dp[i+1];
            }
            
        }

        return nums[0] >= dp[0];
    }
};

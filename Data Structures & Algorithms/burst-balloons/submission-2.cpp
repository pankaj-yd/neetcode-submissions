class Solution {
private:
    int calc(vector<int>& nums, int li, int ri, int lb, int rb, unordered_map<string, int> &cache){
        if(li < 0 || ri >= nums.size() || li > ri){
            return 0;
        }

        if(li == ri){
            return nums[li] * lb * rb;
        }

        string key = to_string(li) + "-" + to_string(ri) + "-" + to_string(lb) + "-" + to_string(rb);

        if(cache.find(key) != cache.end()) return cache[key];
        int ans = 0;
        for(int j = li; j <= ri; j++){
            // calc left
            int left = calc(nums, li, j-1, lb, nums[j], cache);

            // calc right
            int right = calc(nums, j+1, ri, nums[j], rb, cache);

            ans = max(ans, nums[j]*lb*rb + left + right);
        }
        cache[key] = ans;
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, int> cache;
        return calc(nums, 0, n-1, 1, 1, cache);

    }
};

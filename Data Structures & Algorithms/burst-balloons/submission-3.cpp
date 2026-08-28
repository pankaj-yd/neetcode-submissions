class Solution {
private:
    int ans;
    unordered_map<long long, int> cache;
    long long getKey(int x, int y){
        return ((long long)x << 32 | y);
    }

    int calc(vector<int>& nums, int l, int r, int lb, int rb){
        if(l < 0 || r >= nums.size() || l > r){
            return 0;
        }

        if(l == r){
            return lb * nums[l] * rb;
        }

        long long key = getKey(l, r);
        if(cache.find(key) != cache.end()){
            return cache[key];
        }

        int ans = 0;
        
        for(int i = l; i <= r; i++){
            int lval = calc(nums, l, i-1, lb, nums[i]);
            int rval = calc(nums, i+1, r, nums[i], rb);

            ans = max(ans, lval + rval + lb * nums[i] * rb);
        }
        cache[key] = ans;
        return ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        return calc(nums, 0, nums.size()-1, 1, 1);
    }
};

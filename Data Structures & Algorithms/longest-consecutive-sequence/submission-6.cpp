class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int ans = 0;
        for(int num : uset){
            if( uset.find(num-1) == uset.end() ){
                int curr = 1;
                while( uset.find(num + curr) != uset.end() ) {
                    curr++;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

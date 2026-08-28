class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(int n : nums){
            uset.insert(n);
        }

        int ans = 0;
        for(int n : nums){
            if(uset.find(n-1) == uset.end()){
                int count = 1;
                while(uset.find(n + 1) != uset.end()){
                    n++;
                    count ++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

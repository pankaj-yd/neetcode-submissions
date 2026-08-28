class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int ans = 1000;
        int l = 0, r = n;

        while(l < r) {
            int m = l + (r - l) / 2;
            
            ans = min(ans, nums[m]);

            if( nums[m] > nums[r-1]){
                l = m+1;
            } else {
                r = m;
            } 
            
        }
        return ans;
        
    }
};

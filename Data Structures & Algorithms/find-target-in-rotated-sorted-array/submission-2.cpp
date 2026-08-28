class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n;
        int ans = -1;
        while( l < r){
            int m = l + (r - l)/2;
            if( nums[m] == target){
                ans = m;
                break;
            }

            if ( nums[l] <= nums[m]){
                // we are in sorted array
                if ( nums[m] > target && target >= nums[l]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {
                // we are in bad array
                if (nums[m] < target && target <= nums[r-1]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
        }
        
        return ans;
    }
};

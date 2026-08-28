class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n;
        int ans = -1;
        while( l < r){
            int m = l + (r - l)/2;
            cout << "start ----- l: " << l << ", r: " << r << ", m: " << m << "\n";
            if( nums[m] == target){
                ans = m;
                break;
            }

            // does target exists in: m ..... r
            if ( nums[m] < target){
                if(nums[m] <= nums[l] && target > nums[r-1]){
                    r = m;
                } else {
                    l = m + 1;
                }
            } else {
                if (target < nums[r-1] && nums[m] > nums[r-1]) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            cout << "end ----- l: " << l << ", r: " << r << ", m: " << m << "\n";
        }
        
        return ans;
    }
};

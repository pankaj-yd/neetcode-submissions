class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int l = 0, r = 0;
        int curr = -1000;
        int maxI = 0;

        while( r < k ){
            if ( curr <= nums[r] ) {
                curr = nums[r];
                maxI = r;
            }
            r++;
        }
        ans.push_back(curr);
        l++;
        while( r < n){
            // cout << l << " " << r << "\n";
            if ( curr <= nums[r] ) {
                curr = nums[r];
                maxI = r;
            } else if(curr > nums[r] && maxI < l) {
                int i = l;
                curr = nums[l];
                while(i < n && i < l+k){
                    // cout << "i: " << i << "\n";
                    if(curr <= nums[i]) {
                        curr = nums[i];
                        maxI = i;
                    }
                    i++;
                }
            }
            ans.push_back(curr);
            l++;
            r++;
        }
        return ans;
    }
};

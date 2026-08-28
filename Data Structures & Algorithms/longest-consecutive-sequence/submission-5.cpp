class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        sort(nums.begin(), nums.end());
        int ans = 0;
        int curr = 1;
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i] - nums[i-1];
            if( diff == 1 ) { 
                curr += 1;
                cout << diff << " " << curr << "\n";
            }
            if(diff > 1) {
                cout << nums[i] << "\n";
                if(ans < curr){
                    ans = curr;
                }
                curr = 1;
            }
        }
        if(ans < curr) ans = curr;
        return ans;
    }
};

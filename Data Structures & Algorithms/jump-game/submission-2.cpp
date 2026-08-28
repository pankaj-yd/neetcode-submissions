class Solution {
public:
    int canJump(vector<int>& nums) {
        int n = nums.size();

        int far = 0;
        for(int i = 0; i < n; i++){
            if(i <= far){
                far = max(far, i + nums[i]);
                if(far >= n-1) return true;
            }
        }

        return false;

        
    }
};

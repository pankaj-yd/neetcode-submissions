class Solution {
    public int majorityElement(int[] nums) {
        int ans = nums[0];
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (count == 0) {
                ans = nums[i];
                count = 1;
                continue;
            }
            
            if (nums[i] != ans) {
                count--;
            } else {
                count++;
            }
        }
        return ans;
    }
}
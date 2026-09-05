class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] lp = new int[n];

        lp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            lp[i] = lp[i - 1] * nums[i];
        }

        int rp = 1;
        for (int i = n - 1; i > 0; i--) {
            lp[i] = lp[i - 1] * rp;
            rp *= nums[i];
        }
        lp[0] = rp;
        return lp;
    }
}
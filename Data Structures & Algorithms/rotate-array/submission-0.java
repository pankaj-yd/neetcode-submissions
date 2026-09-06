class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if (n == k || k == 0) {
            return;
        }

        k %= n;

        int[] arr = new int[k];
        for(int i = n-1, cnt = k - 1; cnt >= 0; cnt--, i--) {
            arr[cnt] = nums[i];
        }

        for(int i = n - k - 1; i >= 0; i--) {
            nums[i+k] = nums[i];
        }

        for(int i = 0; i < k; i++) {
            nums[i] = arr[i];
        }
    }
}
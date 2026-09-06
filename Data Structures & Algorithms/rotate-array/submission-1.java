class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        if (n == k || k == 0 || k % n == 0) {
            return;
        }

        k %= n;

        int swapped = 0;
        int startIdx = 0;
        int nextIdx = (startIdx + k) % n;
        int currentVal = nums[startIdx];
        while(swapped < n) {
            if (startIdx == nextIdx) {
                nums[nextIdx] = currentVal;
                swapped++;
                startIdx++;
                nextIdx = (startIdx + k) % n;
                currentVal = nums[startIdx];
                continue;
            }

            int nextVal = nums[nextIdx];
            nums[nextIdx] = currentVal;
            currentVal = nextVal;
            nextIdx = (nextIdx + k)%n;
            swapped++;
        }
    }
}
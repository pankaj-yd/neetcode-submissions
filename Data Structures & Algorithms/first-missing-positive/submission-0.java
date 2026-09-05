class Solution {
    private void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public int firstMissingPositive(int[] nums) {
        // if (nums.length == 1 && nums[0] == 1) {
        //     return 2;
        // }
        // 1 .. n
        int n = nums.length;
        boolean nFound = false;
        for (int i = 0; i < nums.length; i++) {
            // System.out.println(Arrays.toString(nums));
            if (nums[i] == n) {
                nFound = true;
            }
            if (nums[i] <= 0 || nums[i] >= n) {
                nums[i] = 0;
                continue;
            }
            while (nums[i] > 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums, i, nums[i]);
            }
            if (nums[i] == n) {
                nFound = true;
            }
            if (nums[i] != i) {
                nums[i] = 0;
            }
        }

        

        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                return i;
            }
        }
        return nFound? n + 1 : n;
    }
}
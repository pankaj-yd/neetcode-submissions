class Solution {
    private int[] tmp;
    private void merge(int[] nums, int l, int m, int r) {

        int i = l, j = m + 1;
        for (int k = l; k <= r; k++) {
            int lv = (i <= m)? nums[i] : (int) 1e7;
            int rv = (j <= r)? nums[j] : (int) 1e7;
            if (lv <= rv) {
                tmp[k] = nums[i++];
            } else {
                tmp[k] = nums[j++];
            }
        }

        for(int k = l; k <= r; k++) {
            nums[k] = tmp[k];
        }
    }

    private void mergeSort(int[] nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = l + (r - l)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }

    public int[] sortArray(int[] nums) {
        tmp = new int[nums.length];
        mergeSort(nums, 0, nums.length - 1);
        return nums;
    }
}

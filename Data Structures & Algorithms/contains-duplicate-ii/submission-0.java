class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> highestIdx = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (highestIdx.containsKey(nums[i])) {
                int idx = highestIdx.get(nums[i]);
                if (i - idx <= k) {
                    return true;
                }
            }
            highestIdx.put(nums[i], i);
        }

        return false;
    }
}
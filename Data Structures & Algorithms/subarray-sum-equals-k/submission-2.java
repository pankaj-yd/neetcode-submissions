class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int ans = 0;
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int sum = prefixSum - k;

            ans += count.getOrDefault(sum, 0);
            count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
        }

        // System.out.println(count.toString());
        return ans;
    }
}
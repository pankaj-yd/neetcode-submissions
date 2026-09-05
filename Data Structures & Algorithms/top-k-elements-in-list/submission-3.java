class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();

        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        List<Integer>[] buckets = new ArrayList[nums.length + 1];
        for (int i = 0; i <= nums.length; i++) {
            buckets[i] = new ArrayList<>();
        }

        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            buckets[entry.getValue()].add(entry.getKey());
        }

        int[] ans = new int[k];
        int i = 0;
        for (int j = nums.length; j >= 0 && i < k; j--) {
            for (int l = 0; l < buckets[j].size(); l++) {
                if (i == k) {
                    return ans;
                }
                ans[i++] = buckets[j].get(l);
            }
        }

        return ans;
    }
}
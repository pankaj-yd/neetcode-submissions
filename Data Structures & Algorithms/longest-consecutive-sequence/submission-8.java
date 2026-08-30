class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> allNums = new HashSet<>(nums.length);
        for (int num : nums) {
            allNums.add(num);
        }

        int maxLen = 0;
        for (int num : nums) {
            if (allNums.contains(num - 1)) {
                continue;
            }

            int currLen = 1;
            while (allNums.contains(num+1)) {
                currLen++;
                num++;
            }
            maxLen = Math.max(maxLen, currLen);
        }

        return maxLen;
    }
}
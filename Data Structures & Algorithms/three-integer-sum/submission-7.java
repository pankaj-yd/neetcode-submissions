class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; i++) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> Integer.compare(nums[i], nums[j]));

        List<List<Integer>> ans = new ArrayList<>();
        // -4, -1, -1, 0, 1, 2
        //      i           k
        for (int i = 0; i < n && nums[idxs[i]] <= 0; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int target = -nums[idxs[i]];

                if (nums[idxs[j]] + nums[idxs[k]] == target) {
                    ans.add(new ArrayList<>(List.of(nums[idxs[i]], nums[idxs[j]], nums[idxs[k]])));
                    while(j < k && nums[idxs[j]] == nums[idxs[j+1]]) {
                        j++;
                    }
                    while (k > j && nums[idxs[k]] == nums[idxs[k-1]]) {
                        k--;
                    }

                    j++;
                    k--;
                } else if (nums[idxs[j]] + nums[idxs[k]] < target) {
                    j++;
                } else {
                    k--;
                }
            }



            while (i < n - 1 && nums[idxs[i]] == nums[idxs[i+1]]) {
                i++;
            }
        }

        return ans;
    }
}


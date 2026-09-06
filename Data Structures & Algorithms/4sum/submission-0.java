class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);

        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        long t = target;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {  
                continue;
            }
            for (int j = i+1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                long sum = t - nums[i] - nums[j];

                int k = j + 1, l = nums.length - 1;
                while (k < l) {
                    if (nums[k] + nums[l] == sum) {
                        ans.add(new ArrayList<>(List.of(nums[i], nums[j], nums[k], nums[l])));
                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k-1]) {
                            k++;
                        }

                        while (k < l && nums[l] == nums[l+1]) {
                            l--;
                        }
                    } else if (nums[k] + nums[l] < sum) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }

        return ans;
    }
}
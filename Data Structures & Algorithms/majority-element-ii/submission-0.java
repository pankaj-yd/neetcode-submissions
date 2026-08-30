class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> ans = new HashMap<>();

        for (int num : nums) {
            ans.put(num, ans.getOrDefault(num, 0) + 1);

            if (ans.size() > 2) {
                Map<Integer, Integer> newAns = new HashMap<>();
                for (Map.Entry<Integer, Integer> entry : ans.entrySet()) {
                    if (entry.getValue() > 1) {
                        newAns.put(entry.getKey(), entry.getValue() - 1);
                    }
                }
            }
        } 
        List<Integer> res = new ArrayList<>();
        for (Integer key : ans.keySet()) {
            int count = 0;
            for (int num : nums) {
                if (key.equals(num)) {
                    count++;
                }
            }

            if (count > n/3) {
                res.add(key);
            }
        }

        return res;
    }
}
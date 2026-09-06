class Solution {
    public int maxArea(int[] h) {
        int n = h.length;

        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            int area = Math.min(h[i], h[j]) * (j - i);
            ans = Math.max(ans, area);
            if (h[i] < h[j]) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
}
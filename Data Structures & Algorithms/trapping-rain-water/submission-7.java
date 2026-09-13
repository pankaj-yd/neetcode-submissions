class Solution {
    public int trap(int[] h) {
        int n = h.length;
        int lm = h[0];
        int rm = h[n-1];

        int i = 0, j = n - 1;
        int ans = 0;
        while(i <= j) {
            lm = Math.max(lm, h[i]);
            rm = Math.max(rm, h[j]);

            if (lm < rm) {
                ans += Math.max(0, Math.min(lm, rm) - h[i]);
                i++;
            } else {
                ans += Math.max(0, Math.min(lm, rm) - h[j]);
                j--;
            }
        }

        return ans;
    }
}
class Solution {
    private boolean checkPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } else {
                return false;
            }
        }

        return true;
    }
    public boolean validPalindrome(String s) {
        int n = s.length();
        int i = 0, j = n - 1;

        boolean deleted = false;
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } else {
                return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
            }
        }

        return true;
    }
}
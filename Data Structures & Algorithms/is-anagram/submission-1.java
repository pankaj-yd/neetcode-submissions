class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] charCount = new int[26];

        for (int i = 0; i < s.length(); i++) {
            int charNum = s.charAt(i) - 'a';
            charCount[charNum] += 1;
        }

        for (int i = 0; i < t.length(); i++) {
            int charNum = t.charAt(i) - 'a';
            charCount[charNum] -= 1;
        }

        for (int num : charCount) {
            if (num != 0) {
                return false;
            }
        }
        return true;
    }
}
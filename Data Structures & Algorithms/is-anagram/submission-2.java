class Solution {
    private int[] charFreq(String a) {
        int[] ans = new int[26];

        for (int i = 0; i < a.length(); i++) {
            int idx = a.charAt(i) - 'a';
            ans[idx]++;
        }
        
        return ans;
    }
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] freqS = charFreq(s);
        int[] freqT = charFreq(t);

        for (int i = 0; i < 26; i++) {
            if (freqS[i] != freqT[i]) {
                return false;
            }
        }

        return true;

    }
}
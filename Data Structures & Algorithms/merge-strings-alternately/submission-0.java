class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder sb = new StringBuilder();

        int i = 0, j = 0;
        int n = word1.length();
        int m = word2.length();

        while(i < n && j < m) {
            sb.append(word1.charAt(i++));
            sb.append(word2.charAt(j++));
    
        }

        if (i == n) {
            sb.append(word2.substring(j));
        } else {
            sb.append(word1.substring(i));
        }

        return sb.toString();
    }
}
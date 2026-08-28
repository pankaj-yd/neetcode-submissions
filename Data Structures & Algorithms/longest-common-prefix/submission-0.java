// More Readable
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 1) {
            return strs[0];
        }

        String lcp = commonString(strs[0], strs[1]);
        for (int i = 2; i < strs.length; i++) {
            lcp = commonString(lcp, strs[i]);
        }

        return lcp;
    }

    private String commonString (String a, String b) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < Math.min(a.length(), b.length()); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                return sb.toString();
            }
            sb.append(a.charAt(i));
        }
        return sb.toString();
    }
}

// Memory Efficient
// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         if (strs.length == 1) {
//             return strs[0];
//         }

//         StringBuilder sb = new StringBuilder();
//         for (int ci = 0; ci < 200; ci++) {
//             char c;
//             if (ci >= strs[0].length()) {
//                 return sb.toString();
//             }
//             c = strs[0].charAt(ci);
//             for (int si = 1; si < strs.length; si++) {
//                 if (strs[si].length() <= ci || c != strs[si].charAt(ci)) {
//                     return sb.toString();
//                 }
//             }
//             sb.append(c);
//         }
//         return sb.toString();
//     }
// }
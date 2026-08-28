// More Readable
// class Solution {
//     public String longestCommonPrefix(String[] strs) {
//         if (strs.length == 1) {
//             return strs[0];
//         }

//         String lcp = commonString(strs[0], strs[1]);
//         for (int i = 2; i < strs.length; i++) {
//             lcp = commonString(lcp, strs[i]);
//         }

//         return lcp;
//     }

//     private String commonString (String a, String b) {
//         StringBuilder sb = new StringBuilder();

//         for (int i = 0; i < Math.min(a.length(), b.length()); i++) {
//             if (a.charAt(i) != b.charAt(i)) {
//                 return sb.toString();
//             }
//             sb.append(a.charAt(i));
//         }
//         return sb.toString();
//     }
// }

// Memory Efficient
class Solution {
    public String longestCommonPrefix(String[] strs) {
        for (int i = 0; i < strs[0].length(); i++) {
            for (String s : strs) {
                if (i == s.length() || s.charAt(i) != strs[0].charAt(i)) {
                    return s.substring(0, i);
                }
            }
        }
        return strs[0];
    }
}
class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s.length());
            sb.append(" ");
            sb.append(s);
        }

        return sb.toString();
    }

    public List<String> decode(String str) {
        List<String> strs = new ArrayList<>();

        int i = 0;
        while (i < str.length()) {
            int j = i;
            while (str.charAt(j) != ' ') {
                j++;
            }

            Integer len = Integer.parseInt(str.substring(i, j));

            strs.add(str.substring(j+1, len + j + 1));
            i = len + j + 1;
        }

        return strs;
    }
}

class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(int i = 0; i < s.size(); i++){
            if('0' <= s[i] && s[i] <= '9'){
                t += s[i];
            }
            if('a' <= s[i] && s[i] <= 'z'){
                t += s[i];
            }
            else if('A' <= s[i]  && s[i] <= 'Z') {
                t += (s[i] - 'A' + 'a');
            }
        }
       
        for(int i = 0; i < t.size()/2; i++){
            if(t[i] != t[t.size() -i -1]) {
                return false;
            }
        }
        return true;
    }
};

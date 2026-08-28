class Solution {
public:
    bool checkInclusion(string s, string t) {
        int k = s.size();
        int n = t.size();
        if(k > n) { return false;}

        vector<int> sm(26, 0);
        for(char c : s){
            sm[c - 'a']++;
        }

        int l = 0, r = 0;
        vector<int> tm(26, 0);

        while(r <= n) {
            int winSz = r - l;
            if(winSz < k) {
                tm[t[r] - 'a']++;
                r++;
            } else {
                int isEqual = true;
                for(int i = 0; i < 26; i++){
                    if(tm[i] != sm[i]){
                        isEqual = false;
                        break;
                    }
                }
                if(isEqual){
                    return true;
                }
                tm[t[l] - 'a'] -= 1;
                l++;
                tm[t[r] - 'a'] += 1;
                r++;
            }
        }
        return false;
        
    }
};

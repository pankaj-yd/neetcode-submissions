int idx(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a';
    }
    else {
        return c - 'A' + 26;
    }
}

bool checkSubstring(vector<int> &tmap, vector<int> &smap){
    for(int i = 0; i < 52; i++){
        if(tmap[i] > smap[i]){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tmap(52, 0);
        for(char c : t){
            tmap[idx(c)]++;
        }
        int k = t.size();
        int n = s.size();
        int l = 0, r = 0;

        vector<int> smap(52, 0);
        while(r < k){
            smap[idx(s[r])]++;
            r++;
        }
        string ans = "";
        while(r <= n){
            if(checkSubstring(tmap, smap)) {
                if(ans.size() > r - l || ans.size() == 0){
                    ans = s.substr(l, r-l);
                }
                smap[idx(s[l])]--;
                l++;
                continue;
            }
            if(r < n){
                smap[idx(s[r])]++;
            }
            r++;
        }
        return ans;
    }
};

pair<int,int> getNum(string s, int startIdx){
    string numS = "";
    while (s[startIdx] != '#') {
        numS += s[startIdx];
        startIdx++;
    }
    return {stoi(numS), startIdx + 1};
}

class Solution {
public:
    string encode(vector<string>& strs) {
        // encoding
        // len1#str1len2str2#len3 ..... 
        string ans = "";
        for(string s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int sS = s.size();
        int i = 0;
        while ( i < sS){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int sz = stoi(s.substr(i, j-i + 1));
            ans.push_back(s.substr(j+1, sz));

            /*
            i . j
            1 # # ........

            */
            i = j + 1 + sz;
        }
        return ans;
    }
};

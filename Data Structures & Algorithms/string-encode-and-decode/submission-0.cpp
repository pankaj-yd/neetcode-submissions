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
        // number of strings # len1 # len2 # len3 # ..... # strings
        string ans = "";
        ans += to_string(strs.size()) + "#";
        for(string s : strs) {
            ans += to_string(s.size()) + "#";
        }
        for(string s : strs) {
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int size;
        int startIdx = 0;
        pair<int,int> start = getNum(s, 0);
        size = start.first;
        startIdx = start.second;
        vector<int> strSizes;
        while(strSizes.size() < size){
            pair<int,int> nextNum = getNum(s, startIdx);
            strSizes.push_back(nextNum.first);
            startIdx = nextNum.second;
        }

        vector<string> ans;
        for(int sz: strSizes){
            string ansS;
            for(int i = startIdx; i < sz+startIdx; i++){
                ansS += s[i];
            }
            ans.push_back(ansS);
            startIdx += sz;
        }
        return ans;
    }
};

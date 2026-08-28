class Solution {
private:
    int getKey(int i, int j){
        return (i << 20) | j;
    }
    unordered_map<int, int> memo;
    int minD(string &s, int i, string &t, int j){
        if(i >= s.size() && j >= t.size()){
            return 0;
        } else if(i >= s.size() || j >= t.size()) {
            int ileft = s.size() - i;
            int jleft = t.size() - j;
            return abs(ileft - jleft);
        }

        int key = getKey(i, j);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        int minEdits = INT_MAX;

        // match
        if(s[i] == t[j]){
            minEdits = min(minEdits, minD(s, i+1, t, j+1));
        }

        // insert
        minEdits = min(minEdits, 1 + minD(s, i, t, j+1));

        // delete
        minEdits = min(minEdits, 1 + minD(s, i+1, t, j));

        // replace
        minEdits = min(minEdits, 1 + minD(s, i+1, t, j+1));
        memo[key] = minEdits;
        return minEdits;
    }

public:
    int minDistance(string s, string t) {
        return minD(s, 0, t, 0);
    }
};

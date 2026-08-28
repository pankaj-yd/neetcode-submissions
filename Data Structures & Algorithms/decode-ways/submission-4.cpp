class Solution {
private:
    bool isValid(string &s, int i, int j){
        string curr = s.substr(i, j - i + 1);
        if(stoi(curr) > 26){
            return false;
        }
        return true;
    }

    int calc(string &s, int i, unordered_map<int, int> &memo){
        if(i >= s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(memo.find(i) != memo.end()){
            return memo[i];
        }
        int curr = 0;
        for(int j = i; j < s.size(); j++){
            if(isValid(s, i, j)){
                int next = calc(s, j+1, memo);
                curr += next;
            } else {
                break;
            }
        }
        memo[i] = curr;

        return curr;
    }

public:
    int numDecodings(string s) {
        unordered_map<int, int> memo;


        return calc(s, 0, memo);
    }
};

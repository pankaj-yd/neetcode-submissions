class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        handleParenthesis(n, 0, 0, "",ans);
        return ans;
        
    }

private:
    void handleParenthesis(int n, int open, int close, string curr,vector<string> &ans){
        if(n == open && open == close) {
            ans.push_back(curr);
            return;
        }

        if(open < n){
            handleParenthesis(n, open+1, close, curr + "(", ans);
        }
        if(close < open){
            handleParenthesis(n, open, close + 1, curr + ")", ans);
        }
        
    }
};

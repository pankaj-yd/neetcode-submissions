class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("", 0, 0, n, ans);
        return ans;
    }

private:
    void generate(string curr, int open, int closed, int n, vector<string> &ans){
        if( n == open && open == closed){
            ans.push_back(curr);
            return;
        }

        if( n > open) {
            generate(curr + "(", open + 1, closed, n, ans);
        }

        if ( open > closed) {
            generate(curr + ")", open, closed + 1, n, ans);
        }
    }
};

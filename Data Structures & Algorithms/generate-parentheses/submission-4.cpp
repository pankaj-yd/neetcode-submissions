class Solution {
private:
    void gen(int n, int i, int open, vector<string> &ans, string &curr){
        cout << curr << endl;
        if(i >= n && open == 0){
            ans.push_back(curr);
        } else if( i >= n){
            return;
        }

        if(open > (n >> 1)){
            return;
        }

        if(open > 0){
            curr.push_back(')');
            gen(n, i+1, open-1, ans, curr);
            curr.pop_back();
        }
        curr.push_back('(');
        gen(n, i+1, open + 1, ans, curr);
        curr.pop_back();
    }
public:
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string curr = "";
        gen(n << 1, 0, 0, ans, curr);
        return ans;
    }

};

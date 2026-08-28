class Solution {
private:
    bool isGood(vector<string> &curr, int i, int j, 
    unordered_set<int> &cols, unordered_set<int> &posDiag, unordered_set<int> &negDiag){
        int n = curr.size();
        // check vertically
        // check up
        if(cols.find(j) != cols.end()){
            return false;
        }

        if(posDiag.find(i + j) != posDiag.end()){
            return false;
        }

        if(negDiag.find(i - j) != negDiag.end()){
            return false;
        }

        return true;
    }

    void solve(vector<vector<string>> &res, vector<string> &curr, int i, int n, 
    unordered_set<int> &cols, unordered_set<int> &posDiag, unordered_set<int> &negDiag){

        if(i == n){
            res.push_back(curr);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isGood(curr, i, j, cols, posDiag, negDiag)){
                curr[i][j] = 'Q';
                cols.insert(j);
                posDiag.insert(i+j);
                negDiag.insert(i-j);
                solve(res, curr, i + 1, n, cols, posDiag, negDiag);
                curr[i][j] = '.';
                cols.erase(j);
                posDiag.erase(i+j);
                negDiag.erase(i-j);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        solve(res, curr, 0, n, cols, posDiag, negDiag);

        return res;
    }
};

class Solution {
private:
    unordered_set<int> colsUsed;
    unordered_set<int> negDiagUsed;
    unordered_set<int> posDiagUsed;
    void solve(int n, int row, vector<string> &curr, vector<vector<string>> &ans){
        if(row >= n){
            ans.push_back(curr);
            return;
        }

        for(int col = 0; col < n; col++){
            if(colsUsed.find(col) == colsUsed.end() 
            && negDiagUsed.find(row - col) == negDiagUsed.end()
            && posDiagUsed.find(row + col) == posDiagUsed.end() ){
                colsUsed.insert(col);
                negDiagUsed.insert(row - col);
                posDiagUsed.insert(row + col);

                curr[row][col] = 'Q';
                solve(n, row + 1, curr, ans);

                curr[row][col] = '.';
                colsUsed.erase(col);
                negDiagUsed.erase(row - col);
                posDiagUsed.erase(row+col);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n){
        vector<string> curr(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(n, 0, curr, ans);
        return ans;
    }
};

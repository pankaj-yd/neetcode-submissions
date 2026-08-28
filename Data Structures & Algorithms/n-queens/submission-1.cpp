class Solution {
private:
    bool isGood(vector<string> &curr, int i, int j){
        int n = curr.size();
        // check vertically
        // check up
        int row = i-1, col = j;
        while(row >= 0){
            if(curr[row][col] == 'Q'){
                return false;
            }
            row--;
        }
       

        // check dia left up
        row = i-1, col = j-1;
        while(row >= 0 && col >= 0){
            if(curr[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }



        // check dia right up
        row = i-1, col = j+1;
        while(row >= 0 && col < n){
            if(curr[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }

        return true;
    }

    void solve(vector<vector<string>> &res, vector<string> &curr, int i, int n){
        if(i == n){
            res.push_back(curr);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isGood(curr, i, j)){
                curr[i][j] = 'Q';
                solve(res, curr, i + 1, n);
                curr[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> curr(n, string(n, '.'));
        solve(res, curr, 0, n);

        return res;
    }
};

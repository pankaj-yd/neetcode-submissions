class Solution {
private:
    void find(vector<vector<char>>& board, string &word, int i , int j, int k, bool &ans){
        if(ans){
            return;
        } else if(k == word.size()){
            ans = true;
            return;
        }
        else if( (i >= board.size() || j >= board[0].size())){
            return;
        } else if (i < 0 || j < 0){
            return;
        }

        if( board[i][j] == word[k]){
            board[i][j] = '-';
            find(board, word, i+1, j, k+1, ans);
            find(board, word, i-1, j, k+1, ans);
            find(board, word, i, j+1, k+1, ans);
            find(board, word, i, j-1, k+1, ans);
            board[i][j] = word[k];
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            if(ans){
                return ans;
            }
            for(int j = 0; j < col; j++){
                if(ans){
                    return ans;
                }
                if(board[i][j] == word[0]){
                    find(board, word, i, j, 0, ans);
                }
            }
        }
        return ans;
    }
};

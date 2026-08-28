class Solution {
    bool exists(vector<vector<char>>& board, int i, int j, string &word, int k){
        if(k == word.size()){
            return true;
        }
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0){
            return false;
        }

        if(board[i][j] == word[k]){
            board[i][j] = '-';
            bool ans = exists(board, i+1, j, word, k+1) 
            || exists(board, i-1, j, word, k+1) 
            || exists(board, i, j+1, word, k+1) 
            || exists(board, i, j-1, word, k+1);
            board[i][j] = word[k];
            return ans;
        }
        return false;
    }

    bool find(vector<vector<char>>& board, string word){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(exists(board, i, j, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(string word : words){
            if(find(board, word)){
                res.push_back(word);
            }
        }
        return res;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j){
        int rows = board.size();
        int cols = board[0].size();


        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != 'O'){
            return;
        }

        board[i][j] = 'T';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int j = 0; j < cols; j++){
            if(board[0][j] == 'O'){
                dfs(board, 0, j);
            }
        }
        for(int j = 0; j < cols ; j++){
            if(board[rows-1][j] == 'O'){
                dfs(board, rows - 1, j);
            }
        }  
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
        } 
        for(int i = 0; i < rows; i++){
            if(board[i][cols-1] == 'O'){
                dfs(board, i, cols-1);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};

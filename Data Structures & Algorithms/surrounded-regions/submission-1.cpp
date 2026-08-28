class Solution {
private:
    void dfs(vector<vector<char>>& board, unordered_set<int> &visited, int i, int j){
        int rows = board.size();
        int cols = board[0].size();

        int cord = i * cols + j;
        if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] == 'X' || visited.find(cord) != visited.end()){
            return;
        }

        visited.insert(cord);
        dfs(board, visited, i+1, j);
        dfs(board, visited, i-1, j);
        dfs(board, visited, i, j+1);
        dfs(board, visited, i, j-1);

    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        unordered_set<int> visited;
        for(int j = 0; j < cols - 1; j++){
            if(board[0][j] == 'O'){
                dfs(board, visited, 0, j);
            }
        }
        for(int j = 0; j < cols - 1; j++){
            if(board[rows-1][j] == 'O'){
                dfs(board, visited, rows - 1, j);
            }
        }  
        for(int i = 0; i < rows - 1; i++){
            if(board[i][0] == 'O'){
                dfs(board, visited, i, 0);
            }
        } 
        for(int i = 0; i < rows - 1; i++){
            if(board[i][cols-1] == 'O'){
                dfs(board, visited, i, cols-1);
            }
        }

        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < cols-1; j++){
                int cord = i * cols + j;
                if(visited.find(cord) == visited.end()){
                    board[i][j] = 'X';
                }
            }
        }

    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row validity
        for(int i = 0; i < 9; i++){
            vector<int> row_map(10,0);
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    if (row_map[idx] > 0) {
                        cout << "Row issue, row number " << i << " ,repeat number " << idx;
                        return false;
                    }
                    row_map[idx]++;
                }
            }
        }
        // check column validity
        for(int j = 0; j < 9; j++){
            vector<int> col_map(10,0);
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.') {
                    int idx = board[i][j] - '0';
                    if (col_map[idx] > 0) {
                        cout << "Column issue, column number " << j << " ,repeat number " << idx;
                        return false;
                    }
                    col_map[idx]++;
                }
            }
        }
        // check sub box validity
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int st_row, st_col;
                st_row = i*3, st_col = j*3;
                vector<int> box_map(10,0);
                for(int k = st_row; k < st_row+3; k++){
                    for(int l = st_col; l < st_col+3; l++){
                        if(board[k][l] != '.') {
                            int idx = board[k][l] - '0';
                            if (box_map[idx] > 0) {
                                cout << "box issue, box number " << j << " ,repeat number " << idx;
                                return false;
                            }
                            box_map[idx]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};

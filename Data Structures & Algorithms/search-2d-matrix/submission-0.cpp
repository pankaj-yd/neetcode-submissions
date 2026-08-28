class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(binSearch(0, matrix.size() * matrix[0].size(), target, matrix) == -1){
            return false;
        }
        return true;
        
    }

private:
    int binSearch(int l, int r, int t, vector<vector<int>>& matrix) {
        if( l == r) {
            return -1;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();

        int m = l + (r - l)/2;
        int row = m/cols;
        int col = m % cols;

        if(matrix[row][col] == t){
            return m;
        } else if(matrix[row][col] > t) {
            return binSearch(l, m, t, matrix);
        } else {
            return binSearch(m+1, r, t, matrix);
        }
        
    }
};

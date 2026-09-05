class NumMatrix {
    private int R;
    private int C;
    private int[][] prefix;
    public NumMatrix(int[][] matrix) {
        R = matrix.length;
        C = matrix[0].length;
        prefix = new int[R+1][C+1];

        for (int r = 0; r < R; r++) {
            prefix[r+1][1] = matrix[r][0];
            for (int c = 1; c < C; c++) {
                prefix[r+1][c+1] = prefix[r+1][c] + matrix[r][c];
            }
        }

        for (int c = 1; c <= C; c++) {
            for (int r = 1; r <= R; r++) {
                prefix[r][c] += prefix[r - 1][c];
            }
        }

        // for (int i = 0; i <= R; i++) {
        //     System.out.println(Arrays.toString(prefix[i]));
        // } 
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row2+1][col1] - prefix[row1][col2 + 1] + prefix[row1][col1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
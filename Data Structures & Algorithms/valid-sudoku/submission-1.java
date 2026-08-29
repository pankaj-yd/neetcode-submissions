class Solution {
    private int[] nums = new int[9];
    private boolean rowChecker(char[][] a) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (a[r][c] == '.') continue;
                nums[a[r][c] - '1']++;
            }

            for (int i = 0; i < 9; i++) {
                if (nums[i] > 1) {
                    return false;
                }
                nums[i] = 0;
            }
        }
        return true;
    }

    private boolean columnChecker(char[][] a) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (a[c][r] == '.') continue;
                nums[a[c][r] - '1']++;
            }

            for (int i = 0; i < 9; i++) {
                if (nums[i] > 1) {
                    return false;
                }
                nums[i] = 0;
            }
        }
        return true;
    }

    private boolean subGridChecker(char[][] a) {
        for (int i = 0; i < 9; i++) {

            for (int r = (i % 3) * 3; r < (i % 3 + 1) * 3; r++) {
                for (int c = (i / 3) * 3; c < (i / 3 + 1) * 3; c++) {
                    if (a[r][c] == '.') continue;
                    nums[a[r][c] - '1']++;
                }
            }

            for (int j = 0; j < 9; j++) {
                if (nums[j] > 1) {
                    return false;
                }
                nums[j] = 0;
            }

        }
        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        return rowChecker(board) && columnChecker(board) && subGridChecker(board);
    }
}
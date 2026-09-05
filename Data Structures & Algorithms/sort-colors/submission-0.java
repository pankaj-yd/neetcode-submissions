class Solution {
    public void sortColors(int[] nums) {
        int red = 0, white = 0, blue = 0;
        for(int num : nums) {
            switch (num) {
                case 0 -> red++;
                case 1 -> white++;
                case 2 -> blue++;
            }
        }

        int i = 0;
        while(i < nums.length) {
            if (red != 0) {
                nums[i++] = 0;
                red--;
            } else if (white != 0) {
                nums[i++] = 1;
                white--;
            } else {
                nums[i++] = 2;
                blue--;
            }
        }
    }
}
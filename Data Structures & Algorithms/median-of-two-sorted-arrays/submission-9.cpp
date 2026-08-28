class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        int median = (n + m + 1)/2;

        int l = 0, r = m;
        while(l <= r){
            int i = l + (r - l)/2;
            int j = median - i;

            int tr = i < m? nums1[i] : INT_MAX;
            int tl = i > 0? nums1[i - 1] : INT_MIN;
            int br = j < n? nums2[j] : INT_MAX;
            int bl = j > 0? nums2[j - 1] : INT_MIN;

            if(tl <= br && bl <= tr){
                if((m + n) % 2 == 1){
                    return max(tl, bl);
                } else {
                    return (max(tl, bl) + min(tr, br))/2.0;
                }
            } else if(tl > br){
                r = i-1;
            } else {
                l = i+1;
            }
        }
        return -1;
    }
};

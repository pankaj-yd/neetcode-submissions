class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();

        int median = (m + n + 1)/2;
        int l = 0, r = m-1;

        while( true ){
            int i = l + (r - l)/2;
            int j = median - i;

            int left1 = i > 0? nums1[i-1] : INT_MIN;
            int right1 = i < m? nums1[i]: INT_MAX;
            int left2 =  j > 0? nums2[j-1] : INT_MIN;
            int right2 = j < n? nums2[j]: INT_MAX;

            if( left1 <= right2 && left2 <= right1){
                if( (m + n)%2 != 0 ){
                    return max(left1, left2);
                } else {
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
            } else if(left1 > right2){
                r = i - 1;
            } else {
                l = i + 1;
            }
        }

        return -1;
    }
};

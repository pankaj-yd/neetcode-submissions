class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        int m = nums1.size(), n = nums2.size();
        int median = (m + n + 1)/2;

        int l = 0, r = m - 1;
        while(true){
            int i = l + (r - l + 1)/2;
            int j = median - i;

            cout << i << " " << j << endl;
            int lval1 = i <= 0 ? INT_MIN : nums1[i-1];
            int rval1 = i >= m? INT_MAX : nums1[i];

            int lval2 = j <= 0? INT_MIN : nums2[j-1];
            int rval2 = j >= n? INT_MAX: nums2[j];

            cout << lval1 << " " << rval1 << endl;
            cout << lval2 << " " << rval2 << endl;
            if(lval1 <= rval2 && lval2 <= rval1){
                if( (m + n)%2 == 0){
                    return (max(lval1, lval2) + min(rval1, rval2))/2.0;
                }
                return max(lval1, lval2);
            }
            if(lval1 <= rval2){
                l = i+1;
            } else {
                r = i-1;
            }
        }

        return -1;
    }
};

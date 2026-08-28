class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binSearch(0, nums.size(), target, nums);
    }

private:
    int binSearch(int l, int r, int t, vector<int>& a){
        if(l == r){
            return -1;
        }
        int m = l + (r - l)/2;

        if(a[m] == t){
            return m;
        } else if( a[m] > t ) {
            return binSearch(l , m, t, a);
        } else {
             return binSearch(m+1 , r, t, a);
        }
    }
};

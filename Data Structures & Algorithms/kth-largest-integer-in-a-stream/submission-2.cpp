class KthLargest {
    int k;
    vector<int> nums;
public:
    KthLargest(int K, vector<int>& n) {
        nums = n;
        sort(nums.begin(), nums.end());
        k = K;
    }
    
    int add(int val) {
        nums.push_back(val);
        int n = nums.size();
        int i = n-2;
        while(i >= 0 && nums[i] > nums[i+1]){
            int tmp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = tmp;
            i--;
        }
        return nums[n-k];
    }
};

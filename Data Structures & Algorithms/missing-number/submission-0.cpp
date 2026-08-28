class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        if(n%2 == 0){
            totalSum = (n/2) * (n+1);
        }else {
            totalSum = n * ((n+1)/2);
        }
       
        for(int num : nums) totalSum -= num;

        return totalSum;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int st = 0;
        int n = arr.size();

        int curr = n-1;
        while(true) {
            if(arr[st] + arr[curr] == target) {break;}
            if(arr[st] + arr[curr] < target) {
                st++;
            } else {
               curr--;
            }
        }
        return {st+1, curr+1};
    }
};

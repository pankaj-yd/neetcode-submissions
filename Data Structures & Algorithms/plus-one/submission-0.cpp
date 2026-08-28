class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();
        int carry = 1;
        for(int i = n-1; i>= 0; i--){
            arr[i] += carry;
            carry = arr[i]/10;
            arr[i] %= 10;
            
        }

        if(carry){
           arr.insert(arr.begin(), carry);
        }
        return arr;
    }
};

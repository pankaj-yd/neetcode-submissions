class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos = nums[0] > 0? nums[0] : 0;
        int neg = nums[0] > 0? 0 : nums[0];
        int ans = max(pos, neg);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0){
                pos = 0;
                neg = 0;
                cout << "pos: " << pos << " " << "neg: " << neg << endl;
            } else if(nums[i] > 0){
                int newNeg = neg * nums[i];
                int newPos = pos * nums[i];
                if(pos == 0) pos = nums[i];
                else pos *= nums[i];
                neg = newNeg;
                cout << "pos: " << pos << " " << "neg: " << neg << endl;
                ans = max(ans, pos);
            } else {
                int newNeg = pos * nums[i];
                int newPos = neg * nums[i];
                
                neg = newNeg;
                ans = max(pos, newPos);
                pos = newPos;
                cout << "pos: " << pos << " " << "neg: " << neg << endl;
            }
        
        }
        if(ans == 0){return neg;}
        return ans;
    }
};

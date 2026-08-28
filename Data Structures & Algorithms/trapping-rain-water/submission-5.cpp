class Solution {
public:
    int trap(vector<int>& h){
        int n = h.size();

        int total = 0;

        int l = 0, r = n-1;
        int lm = h[0], rm = h[r];
        while(l <= r){
            if(lm < rm){
                total += max(0, lm - h[l]);
                lm = max(lm, h[l]);
                l++;
            }else{
                total += max(0, rm - h[r]);
                rm = max(rm, h[r]);
                r--;
            }
            
        }
        

        return total;
    }
};

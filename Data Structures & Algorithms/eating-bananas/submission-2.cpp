class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = piles[0];
        for(int ban : piles){
            maxB = max(maxB, ban);
        }

        int n = piles.size();
        int l = 1, r = maxB+1;
        int ans = -1;
        while(l < r){
            int m = l + (r - l)/2;
            // calculate time
            int time = 0;
            for(int ban : piles){
                time += ban/m;
                if(ban % m != 0) {
                    time++;
                }
            }
            if ( time > h){
                l = m+1;
            } else {
                ans = m;
                r = m;
            }
        }
        return ans;
        
    }
};

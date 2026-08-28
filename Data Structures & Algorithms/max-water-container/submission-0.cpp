class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();

        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                int water = min(h[i], h[j])* (j-i);
                ans = max(ans, water);
            }
        }
        return ans;
    }
};

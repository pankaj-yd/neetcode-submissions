class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int minH = h[i];
            for(int j = i; j < n; j++){
                minH = min(minH, h[j]);
                ans = max(ans, (j - i + 1)* minH );
            }
        }

        return ans;
    }
};

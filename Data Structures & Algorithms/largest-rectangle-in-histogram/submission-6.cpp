class Solution {
public:
    int largestRectangleArea(vector<int>& h){
        int n = h.size();
        int area = 0;

        for(int i = 0; i < n; i++){
            int minH = h[i];
            for(int j = i; j < n; j++){
                minH = min(minH, h[j]);
                area = max(area, (j - i + 1) * minH);
            }
        }

        return area;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<pair<int, int>> s;
        int ans = 0;
        int i = 0;
        while(i < n){
            int lastIdx = i;

            while(!s.empty() && s.top().second > h[i]) {
                int prevH = s.top().second;
                int prevI = s.top().first;
                lastIdx = prevI;
                ans = max(ans, (i - prevI) * prevH );
                s.pop();
            }

            s.push({lastIdx, h[i]});

            // ans = max(ans, (i - lastIdx + 1) * h[i]);
            i++;
        }

        int topIdx = s.top().first;
        while(!s.empty()){
            ans = max(ans, (topIdx - s.top().first + 1) * s.top().second);
            s.pop();
        }

        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> s;

        int area = 0;
        for(int i = 0; i < n; i++){
            while(!s.empty() && h[s.top()] > h[i]){
                int top = s.top();
                s.pop();
                int idx = (i - top);
                if(s.empty()){
                    idx += top;
                } else {
                    idx += (top - s.top() - 1 );
                }
                area = max(area, idx * h[top]);
            }
            s.push(i);
        }

        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            int idx = n - top;
            if(s.empty()){
                idx += top;
            } else {
                idx += (top - s.top() - 1 );
            }
            area = max(area, idx * h[top]);
        }

        return area;
    }
};
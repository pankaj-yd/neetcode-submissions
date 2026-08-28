class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> q;

        int n = t.size();
        vector<int> ans(n, 0);
        
        int i = 0;
        while( i < n){
            while(!q.empty() && t[q.top()] < t[i]){
                ans[q.top()] = i - q.top();
                q.pop();
            }
            q.push(i);
            i++;
        }
        return ans;
    }
};

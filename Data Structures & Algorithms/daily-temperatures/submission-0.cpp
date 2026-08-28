class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        deque<int> q;

        int n = t.size();
        vector<int> ans(n, 0);
        
        int i = 0;
        while( i < n){
            while(!q.empty() && t[q.back()] < t[i]){
                ans[q.back()] = i - q.back();
                q.pop_back();
            }
            q.push_back(i);
            i++;
        }
        return ans;
    }
};

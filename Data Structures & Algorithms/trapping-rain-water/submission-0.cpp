class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        int i = 0;
        int si = 0;
        vector<int> lm(n, 0);
        vector<int> rm(n, 0);
        lm[0] = h[0];
        cout << lm[0] << " ";
        for(int i = 1; i < n; i++){
            lm[i] = max(lm[i-1], h[i]);
            cout << lm[i] << " ";
        }
        cout << "\n\n";
        rm[n-1] = h[n-1];
        for(int i = n-2; i >= 0; i--){
            rm[i] = max(rm[i+1], h[i]);
        }
        for(int i = 0; i < n; i++) {
            cout << rm[i] << " ";
        }
        cout << "\n";
        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += max(min(lm[i], rm[i]) - h[i], 0);
        }
        return ans;

        
    }
};

class Solution {
private:
    int count(int n, vector<int> &ans){
        int total = 0;
        while(n > 0){
            if(ans[n] != -1){
                total += ans[n];
                break;
            }
            n &= n-1;
            total++;
        }
        return total;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);
        ans[0] = 0;

        for(int i = 1; i <= n; i++){
            ans[i] = count(i, ans);
        }

        return ans;
    }
};

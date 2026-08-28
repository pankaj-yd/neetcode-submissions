pair<int, int> calc(vector<int> &cc){
    int maxSame = 0, diff = 0;
    for(int n : cc) {
        cout << n << " ";
        if(maxSame < n){
            diff += maxSame;
            maxSame = n;
        } else {
            diff += n;
        }
    }
    cout << "\n";
    return {maxSame, diff};
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int a = 0, b = 0;
        int l = 0, r = 0;
        int ans = 0;
        vector<int> cc(26, 0);
        while (l < n && r < n) {
            cc[s[r] - 'A'] += 1;

            pair<int, int> count = calc(cc);
            cout << "diff sum : " << count.second << "\n";
            if(count.second > k) {
                cc[s[l] - 'A'] -= 1;
                l++;
            } else {
                ans = max(ans, r-l + 1);
            }
            r++;
        }
        cout << "l " << l << ", " << "r " << r << "\n";
        ans = max(ans, r - l);
        return ans;
        
    }
};

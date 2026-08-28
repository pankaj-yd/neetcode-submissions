class Solution {
private:
    int isPossible(char c1, char c2){
        if(c1 == '0' || (c1 - '0') * 10 + (c2 - '0')  > 26 ) return 0;
        return 1;
    }
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        int n = s.size();
        vector<int> dec(n, 0);
        dec[0] = 1;
        for(int i = 1; i < n; i++){
            int count = 0;
            if(s[i] == '0'){
                if(!isPossible(s[i-1], s[i])){
                    return 0;
                }
                if(i > 1){
                    dec[i] = dec[i-2];
                } else {
                    dec[i]++;
                }
            } else {
                dec[i] = dec[i-1];
                if(isPossible(s[i-1], s[i])){
                    if(i > 1){
                        dec[i] += dec[i-2];
                    } else {
                        dec[i]++;
                    }
                }
            }
        }
        return dec[n-1];
    }
};

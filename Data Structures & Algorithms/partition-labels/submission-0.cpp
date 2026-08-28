class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end(26, -1);
        for(int i = 0; i < s.length(); i++){
            end[s[i] - 'a'] = i;
        }
        vector<int> count;
        for(int i = 0; i < s.length(); i++){
            int endIdx = end[s[i] - 'a'];
            int startIdx = i;
            while(i < endIdx){
                i++;
                endIdx = max(endIdx, end[s[i] - 'a']);
            }
            count.push_back(endIdx - startIdx + 1);
        }

        return count;
    }
};

class Solution {
private:
    bool isPal(string &s, int start, int end){
        for(int i = start; i <= end; i++){
            if(s[i] != s[end - i + start]){
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s){
        if(s.size() == 0){
            return {{}};
        }
        vector<vector<string>> ans;

        for(int i = 0; i < s.size(); i++){
            if(isPal(s, 0, i)){
                vector<vector<string>> res = partition(s.substr(i+1, s.size() - i - 1));
                if(res.size() > 0){
                    for(vector<string> v : res){
                        v.push_back(s.substr(0, i+1));
                        ans.push_back(v);
                    }
                }
            }
        }
        return ans;
    }
};

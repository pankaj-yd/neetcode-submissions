class Solution {
private:
    bool check(string &s, int i, int op){
        if(i >= s.size() && op == 0) return true;
        if(i >= s.size() || op < 0) return false;

        bool isStar = s[i] == '*';
        if(isStar){
            bool open =  check(s, i+1, op+1);

            bool close =  check(s, i+1, op-1);

            bool ignore = check(s, i+1, op);

            return open || close || ignore;
        }

        if(s[i] == '(') {
            return check(s, i+1, op+1);
        }
        else if(s[i] == ')'){
            return check(s, i+1, op-1);
        }
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        return check(s, 0, 0);
    }
};

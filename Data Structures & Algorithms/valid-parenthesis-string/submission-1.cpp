class Solution {
private:
    bool check(string &s, int i, stack<char> &st){
        // cout << i << " " << st.size() << endl;
        if(i >= s.size() && st.empty()) return true;
        if(i >= s.size()) return false;

        bool isStar = s[i] == '*';
        if(isStar){
            s[i] = '(';
            // cout << "considering open" << endl;
            bool open =  check(s, i, st);

            // cout << "considering close" << endl;
            s[i] = ')';
            bool close =  check(s, i, st);

            // cout << "ignore" << endl;
            bool ignore = check(s, i+1, st);

            return open || close || ignore;
        }

        if(s[i] == '(') {
            st.push('(');
            bool ans = check(s, i+1, st);
            st.pop();
            return ans;
        }
        else if(s[i] == ')'){
            if(st.empty()) return false;
            st.pop();
            bool ans =  check(s, i+1, st);
            st.push('(');
            return ans;
        }
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<char> st;
        return check(s, 0, st);
    }
};

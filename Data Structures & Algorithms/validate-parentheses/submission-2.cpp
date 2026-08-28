class Solution {
public:
    bool isValid(string t) {
        stack<char> s;
        for(char c : t){
            if(!s.empty()){
                if(c == ')' && s.top() == '('){
                    s.pop();
                }else if(c == '}' && s.top() == '{'){
                    s.pop();
                }else if(c == ']' && s.top() == '['){
                    s.pop();
                } else if ( c == '(' || c == '{' || c == '[' ){
                    s.push(c);
                } else {
                    return false;
                }
            } else {
               if ( c == '(' || c == '{' || c == '[' ){
                    s.push(c);
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

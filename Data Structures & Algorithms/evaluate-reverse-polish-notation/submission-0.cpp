class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int val = 0;
        for(string t : tokens){
            if(t == "*" || t == "+" || t == "/" || t == "-"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                if(t == "+") s.push(first + second);
                else if(t == "-") s.push(first - second);
                else if(t == "*") s.push(first * second);
                else s.push(first/second);

            } else {
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};

class Solution {


public:
    bool checkValidString(string s){
        const char open = '(', close = ')', star = '*';
        stack<int> opens;
        stack<int> stars;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == open){
                opens.push(i);
                
            } else if (ch == star){
                stars.push(i);
            } else {
                // it is an close
                // remove an open bracket 
                if(!opens.empty()){
                    opens.pop();
                } else {
                    // we do not have open bracket
                    // make star an open bracket and pop
                    while(!stars.empty() && stars.top() > i){
                        stars.pop();
                    }
                    if(stars.empty()){
                        return false;
                    }
                    stars.pop();
                }
            }   
        }

        while(!opens.empty()){
            if(stars.empty() || stars.top() < opens.top()){
                return false;
            }

            opens.pop();
            stars.pop();
        }

        return true;
    }
};

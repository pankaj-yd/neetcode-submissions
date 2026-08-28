class Solution {
public:
    bool checkValidString(string s){
        int openMin = 0, openMax = 0;

        for(char ch : s){
            if(ch == '('){
                openMin++, openMax++;
            } else if(ch == ')'){
                openMax--;
                openMin--;
            } else {
                openMax++;
                openMin--;
            }

            if (openMax < 0) {
                return false;
            }

            if(openMin < 0){
                openMin = 0;
            }
        }

        return openMin == 0;
    }
};

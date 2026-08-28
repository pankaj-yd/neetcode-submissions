class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 1 && num1[0] == '0') return "0";
        if(num2.size() == 1 && num2[0] == '0') return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> prev;

        for(int j = 0; j < num2.size(); j++){
            int carry = 0;
            vector<int> curr(j, 0);
            cout << num1 << " * " << num2[j] << endl;
            for(int i = 0; i < num1.size(); i++){
                int mult = (num2[j] - '0') * (num1[i] - '0') + carry;
                carry = mult/10;
                mult %= 10;
                curr.push_back(mult);
            }
            if(carry) curr.push_back(carry);

            cout << "multiply ans: ";
            for(int i = 0; i < curr.size(); i++){
                cout << curr[i];
            }
            cout << endl;

            int prevSize = prev.size(), currSize = curr.size();
            carry = 0;
            int k = 0;
            while(k < currSize){
                if(k < prevSize){
                    curr[k] += prev[k];
                }
                curr[k] += carry;
                carry = curr[k]/10;
                curr[k] %= 10;
                k++;
            }
            if(carry) curr.push_back(carry);

            cout << "addition ans: ";
            for(int i = 0; i < curr.size(); i++){
                cout << curr[i];
            }
            cout << endl;

            prev = curr;
        }

        string ans;
        for(int i : prev){
            ans.push_back(i + '0');
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

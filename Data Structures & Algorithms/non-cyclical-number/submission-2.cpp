class Solution {
private:
    int getNext(int n){
        int sum = 0;
        while(n > 0){
            int digit = n%10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        
        while(slow != fast){
            
            fast = getNext(getNext(fast));

            slow = getNext(slow);
        }

        return fast == 1;
    }
};

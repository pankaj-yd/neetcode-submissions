class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        int n = hand.size();
        if(n % s != 0) return false;

        unordered_map<int, int> count;
        for (int n : hand)
            count[n] = 1 + count[n];

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& pair : count)
            pq.push(pair.first);
        
        while(!pq.empty()){
            int top = pq.top();
            if(count[top] > 0) {
                count[top]--;
            } else {
                pq.pop();
                continue;
            }

            for(int i = 1; i < s; i++){
                if(count.find(i + top) != count.end() && count[i+top] > 0){
                    count[i+top]--;
                } else {
                    return false;
                }
            }
        }

        return true;

    }
};

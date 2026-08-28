class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int s) {
        int n = hand.size();
        if(n % s != 0) return false;

        int g = n/s;
        sort(hand.begin(), hand.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        int i = 0;
        int count = 0;
        vector<int> groups(g+1, 0);
        while(i < n && count <= g){
            // remove full groups
            while(!pq.empty() && groups[pq.top().second] == s){
                pq.pop();
            }

            if(pq.empty()){
                pq.push({hand[i], count});
                groups[count]++;
                count++;
            } else {
                pair<int, int> top = pq.top();
                if(top.first + 1 == hand[i]){
                    pq.pop();
                    groups[top.second]++;
                    pq.push({hand[i], top.second});
                } else {
                    pq.push({hand[i], count});
                    groups[count]++;
                    count++;
                }
            }
            i++;
        }

        return groups[g] == 0;
    }
};

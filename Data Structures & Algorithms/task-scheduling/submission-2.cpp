

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }
        

        priority_queue<int, vector<int>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        queue<pair<int,int>> q;

        int time = 0;
        while( !pq.empty() || !q.empty()){
            if(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()){
                int curr = pq.top();
                pq.pop();
                curr--;
                if(curr > 0){
                    q.push({curr, time + k + 1});
                }
            }
            time++;
        }

        return time;
    }
};

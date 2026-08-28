class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        vector<int> freq(26, 0);
        for(char c : tasks){
            freq[c - 'A']++;
        }

        priority_queue<vector<int>, vector<vector<int>> >maxHeap;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i], 0});
            }
        }

        queue<vector<int>> q;
        int t = 0;
        while(!maxHeap.empty() || !q.empty()){
            while(!q.empty() && q.front()[1] <= t){
                maxHeap.push(q.front());
                q.pop();
            }

            if(!maxHeap.empty()){
                vector<int> top = maxHeap.top();
                maxHeap.pop();
                if(top[0] > 1){
                    q.push({top[0]-1, top[1] + k + 1});
                }
            }

            t++;
        }

        return t;
    }
};

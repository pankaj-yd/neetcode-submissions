class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int, vector<int>> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(abs(stone1 - stone2));
        }
        return maxHeap.top();

    }
};

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums){
        this->k = k;

        for(int num : nums){
            pq.push(num);
            if(pq.size() > this->k){
                pq.pop();
            }
        }
    }

    int add(int num){
        pq.push(num);
        if(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};

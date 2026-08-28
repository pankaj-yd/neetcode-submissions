class MedianFinder {
private:
    priority_queue<int, vector<int> > leftMaxHeap;
    priority_queue<int, vector<int>, greater<int> > rightMinHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if ( !leftMaxHeap.empty() ){
            if(num < leftMaxHeap.top()) {
                leftMaxHeap.push(num);

                if(leftMaxHeap.size() > rightMinHeap.size() + 1){
                    int leftTop = leftMaxHeap.top();
                    leftMaxHeap.pop();
                    rightMinHeap.push(leftTop);
                }

            } else {
                rightMinHeap.push(num);
                if (rightMinHeap.size() > leftMaxHeap.size()){
                    int rightTop = rightMinHeap.top();
                    rightMinHeap.pop();
                    leftMaxHeap.push(rightTop);
                }
            }
        } else {
            leftMaxHeap.push(num);
        }




    }
    
    double findMedian() {
        if ( leftMaxHeap.size() > rightMinHeap.size()){
            return leftMaxHeap.top();
        }
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

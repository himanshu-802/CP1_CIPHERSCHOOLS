class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);// cout<<maxHeap.size()<<endl;
        minHeap.push(maxHeap.top()); // cout<<maxHeap.size()<<endl;
        maxHeap.pop(); //cout<<maxHeap.size()<<endl
        if(maxHeap.size()< minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return double(maxHeap.top());
        }
        else{
            return (double(maxHeap.top() + minHeap.top()))/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

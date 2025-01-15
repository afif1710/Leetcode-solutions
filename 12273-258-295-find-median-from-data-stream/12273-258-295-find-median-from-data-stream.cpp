class MedianFinder {
public:
    
    MedianFinder() {
      
    }
    priority_queue<double> left_max_heap;
    priority_queue<double, vector<double>, greater<double>> right_min_heap;
    void addNum(int num) {
        if(left_max_heap.empty() || num<left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }

        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(left_max_heap.size() < right_min_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }

    }
    
    double findMedian() {
        
        double res = 0.0;
        if(left_max_heap.size() == right_min_heap.size()){
            res = (left_max_heap.top() + right_min_heap.top()) / 2;
            return res;
        }else{
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
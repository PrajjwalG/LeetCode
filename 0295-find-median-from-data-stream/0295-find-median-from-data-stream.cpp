class MedianFinder {
public:
    priority_queue<int> first;
    priority_queue<int,vector<int>,greater<int>>second;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty() or first.top() > num) first.push(num);
        else second.push(num);
        
        if(first.size() > second.size() + 1)
        {
            second.push(first.top());
            first.pop();
        }
        
        else if(first.size() + 1 < second.size())
        {
            first.push(second.top());
            second.pop();
        }
        
    }
    
    double findMedian() {
        if(first.size() == second.size()) return first.size() == 0 ? 0 : (double(first.top()) + second.top())/2;
        
        return first.size() > second.size() ? first.top():second.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
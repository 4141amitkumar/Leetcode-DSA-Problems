class MedianFinder {
public:
    priority_queue<int> pqmax;
    priority_queue<int,vector<int>,greater<int>> pqmin;
    MedianFinder() {  //default constructor
        //heap method
    }
    
    void addNum(int num) {
        if(pqmax.empty() || num<=pqmax.top()) pqmax.push(num);
        else pqmin.push(num);
        if(pqmax.size()>pqmin.size()+1){
            int x = pqmax.top();
            pqmax.pop();
            pqmin.push(x);
        }
        else if(pqmin.size()>pqmax.size()+1){
            int x = pqmin.top();
            pqmin.pop();
            pqmax.push(x);
        }
    }
    
    double findMedian() {
        if(pqmin.size()==pqmax.size()) return (pqmin.top()+pqmax.top())/2.0;
        else if(pqmin.size()>pqmax.size()) return pqmin.top();
        else return pqmax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class RecentCounter {
public:
    queue<int> v;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        v.push(t);
        while(v.front() < t - 3000){
            v.pop();
        }
        return v.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
class SmallestInfiniteSet {
private:
    int cur;
    set<int> v;

public:
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        if (!v.empty()) {
            int x = *v.begin();
            v.erase(v.begin());
            return x;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur) {
            v.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
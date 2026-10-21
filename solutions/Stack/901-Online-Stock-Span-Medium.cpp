class StockSpanner {
public:
    StockSpanner() {
        
    }

    vector<pair<int, int>> v;
    int pos = 0;

    int next(int price) {
        while (!v.empty() && v.back().first <= price) {
            v.pop_back();
        }

        int ans = v.empty() ? pos + 1 : pos - v.back().second;

        v.push_back({price, pos});
        pos++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
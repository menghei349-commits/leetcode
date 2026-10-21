class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> v, v1;
        int i = 0, j = costs.size()-1;

        for(int it = 0; it < candidates; it++){
            if(i <= j) v.push(costs[i++]);
            if(i <= j) v1.push(costs[j--]);
        }

        long long ans = 0;
        while(k--){
            if(v1.empty() || (!v.empty() && v.top() <= v1.top())){
                ans += v.top();
                v.pop();
                if(i <= j) v.push(costs[i++]);
            }else{
                ans += v1.top();
                v1.pop();
                if(i <= j) v1.push(costs[j--]);
            }
        }
        return ans;
    }
};
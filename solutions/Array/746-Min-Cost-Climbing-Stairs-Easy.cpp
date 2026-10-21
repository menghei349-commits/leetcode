class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v;
        v.push_back(cost[0]);
        v.push_back(cost[1]);

        for(int i=2; i<cost.size(); i++){
            v.push_back(min(v[i-2], v[i-1]) + cost[i]);
        }

        return min(v[v.size()-1], v[v.size()-2]);
    }
};
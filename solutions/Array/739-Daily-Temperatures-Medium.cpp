class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> v;
        
        for (int i=0; i<n; i++){
            while (!v.empty() && temperatures[i] > temperatures[v.top()]) {
                int j = v.top();
                v.pop();
                ans[j] = i - j;
            }
            v.push(i);
        }

        return ans;
    }
};
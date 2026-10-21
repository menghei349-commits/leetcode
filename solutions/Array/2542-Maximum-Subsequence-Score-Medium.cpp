class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums1.size(); i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.rbegin(), arr.rend());
        
        priority_queue<int, vector<int>, greater<int>> v;
        long long sum = 0, ans = 0;
        
        for (auto& it : arr) {
            v.push(it.second);
            sum += it.second;
            if (v.size() > k) {
                sum -= v.top();
                v.pop();
            }
            if (v.size() == k) {
                ans = max(ans, sum * it.first);
            }
        }
        return ans;
    }
};
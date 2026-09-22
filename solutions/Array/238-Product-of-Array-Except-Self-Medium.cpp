class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v, v1, ans;

        v.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            v.push_back(v[i-1] * nums[i]);
        }

        v1.push_back(nums[n-1]);
        for (int i = n-2, j = 0; i > 0; i--, j++) {
            v1.push_back(v1[j] * nums[i]);
        }

        for (int i = 0; i < n; i++) {
            int left  = (i == 0) ? 1 : v[i-1];
            int right = (i == n-1) ? 1 : v1[n-2-i];
            ans.push_back(left * right);
        }
        return ans;
    }
};
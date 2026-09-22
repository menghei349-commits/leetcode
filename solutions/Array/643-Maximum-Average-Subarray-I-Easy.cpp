class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int q = 0;
        double ans;
        for(int i=0; i<k; i++){
            q += nums[i];
        }
        ans = q;

        for(int i=k; i<nums.size(); i++){
            q -= nums[i-k];
            q += nums[i];
            ans = max(ans, (double)q);
        }

        return ans / k;
    }
};
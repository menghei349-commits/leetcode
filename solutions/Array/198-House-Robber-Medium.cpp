class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums.back();
        vector<int> v;
        v.push_back(nums[0]);
        v.push_back(max(nums[1], nums[0]));

        for(int i=2; i<nums.size(); i++){
            v.push_back(max(v[i-2]+nums[i], v[i-1]));
        }

        return max(v[v.size()-2], v[v.size()-1]);
    }
};
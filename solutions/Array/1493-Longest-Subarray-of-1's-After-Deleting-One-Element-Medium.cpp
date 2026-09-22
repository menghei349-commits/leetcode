class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v;
        int ans = 0, q = 0, t = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                q++;
                t++;
            }else{
                v.push_back(q);
                q = 0;
            }
        }

        v.push_back(q);
        v.push_back(0);
        for(int i=0; i<v.size()-1; i++){
            ans = max(ans, v[i] + v[i+1]);
        }

        if(t == nums.size()) return ans-1;
        return ans;
    }
};
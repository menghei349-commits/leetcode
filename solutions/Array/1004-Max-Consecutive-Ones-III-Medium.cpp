class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = 0, ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) k--;

            while(k < 0){
                if(nums[n] == 0) k++;
                n++;
            }

            ans = max(ans, i - n + 1);
        }

        return ans;
    }
};
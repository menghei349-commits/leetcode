class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while(true){
            auto it = lower_bound(nums.begin(), nums.end(), original);
            if(it != nums.end() && *it == original){
                original *= 2;
            }else{
                break;
            }
        }

        return original;
    }

};
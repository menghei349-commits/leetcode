class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> v;
        for(auto it : nums){
            v.insert(it);
        }

        int i = 0;
        for(auto it : v){
            nums[i] = it;
            i++;
        }

        return v.size();
    }
};
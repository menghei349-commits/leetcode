class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            v.push_back(nums[i] + v.back());
        }

        for(int i=0; i<v.size(); i++){
            if(i == 0 && v[v.size()-1] - v[i] == 0) return 0;
            else if(i == v.size()-1 && v[v.size()-2] == 0) return v.size()-1;
            else if(i != 0 && i != v.size()-1 && v[v.size()-1] - v[i] == v[i-1]) return i;
        }


        return -1;
    }
};
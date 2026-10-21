class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> v;
        for(auto it : nums){
            if(v.count(it)){
                v.erase(it);
            }else{
                v.insert(it);
            }
        }

        return *v.begin();
    }
};
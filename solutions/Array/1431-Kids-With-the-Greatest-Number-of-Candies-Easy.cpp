class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> v = candies;
        vector<bool> ans;
        sort(v.begin(), v.end());
        int q = v.back();

        for(auto it : candies){
            if(it + extraCandies >= q){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }

        return ans;
    }
};
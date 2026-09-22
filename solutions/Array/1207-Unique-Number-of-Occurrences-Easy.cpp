class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> v;
        set<int> v1;
        for(auto it : arr){
            v[it]++;
        }

        for(auto it : v){
            if(v1.count(it.second)) return 0;
            v1.insert(it.second);
        }

        return 1;
    }
};
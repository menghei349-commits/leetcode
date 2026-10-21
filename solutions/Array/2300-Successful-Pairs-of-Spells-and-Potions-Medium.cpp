class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        sort(potions.begin(), potions.end());
        int m = potions.size();
        for (auto it : spells) {
            int i = 0, j = m;
            while (i != j) {
                int mid = (i + j) / 2;
                if ((long long)it * potions[mid] >= success)
                    j = mid;
                else
                    i = mid + 1;
            }
            v.push_back(m - i);
        }
        return v;
    }
};
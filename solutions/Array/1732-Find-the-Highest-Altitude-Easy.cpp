class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, n = 0;
        for(int i=0; i<gain.size(); i++){
            n += gain[i];
            ans = max(ans, n);
        }

        return ans;
    }
};
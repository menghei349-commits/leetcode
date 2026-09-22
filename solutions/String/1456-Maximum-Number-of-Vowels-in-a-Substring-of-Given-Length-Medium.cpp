class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> v{'a','e','i','o','u'};
        int ans, q = 0;
        for(int i=0; i<k; i++){
            if(v.count(s[i])) q++;
        }

        ans = q;
        for(int i=k; i<s.size(); i++){
            if(v.count(s[i])) q++;
            if(v.count(s[i-k])) q--;
            ans = max(ans, q);
        }

        return ans;
    }
};
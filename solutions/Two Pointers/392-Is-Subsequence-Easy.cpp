class Solution {
public:
    bool isSubsequence(string s, string t) {
        int q = 0, ans = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=q; j<t.size(); j++){
                if(s[i] == t[j]){
                    q = j + 1;
                    ans++;
                    break;
                }
            }
        }

        if(ans == s.size()) return 1;
        return 0;
    }
};
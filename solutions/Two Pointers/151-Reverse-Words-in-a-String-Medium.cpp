class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stringstream S(s);

        while(getline(S, s, ' ')){
            if(s != "") ans = s + " " + ans;
        }
        
        ans.erase(ans.size()-1, 1);
        return ans;
    }
};
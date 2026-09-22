class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        string s;
        stringstream s1(text);
        set<char> c;
        vector<string> v;

        while(getline(s1, s, ' ')){
            v.push_back(s);
        }

        for(auto it : brokenLetters){
            c.insert(it);
        }

        for(auto s : v){
            int q = 0;
            for(auto it : s){
                if(c.count(it)){
                    q++;
                    break;
                }
            }
            if(q == 0){
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> v;
        string ans = "";
        int q = 0;

        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                q = q * 10 + (s[i] - '0');
            }else if(s[i] == '['){
                v.push({ans, q});
                ans = "";
                q = 0;
            }else if(s[i] == ']'){
                string t = v.top().first;
                int k = v.top().second;
                v.pop();
                for(int j=0; j<k; j++){
                    t += ans;
                }
                ans = t;
            }else{
                ans += s[i];
            }
        }
        
        return ans;
    }
};
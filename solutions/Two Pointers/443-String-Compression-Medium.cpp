class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> v;
        char c = chars[0];
        int n = 1;

        for(int i=1; i<chars.size(); i++){
            if(c != chars[i]){
                v.push_back(c);
                string s = to_string(n);
                if(n != 1){
                    for(int i=0; i<s.size(); i++){
                        v.push_back(s[i]);
                    }
                }
                n = 1;
                c = chars[i];
            }else{
                n++;
            }
        }

        v.push_back(c);
        string s = to_string(n);
        if(n != 1){
            for(int i=0; i<s.size(); i++){
                v.push_back(s[i]);
            }
        }
        chars = v;
        return v.size();
    }
};
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;   
        vector<int> v(26, 0), v1(26, 0);

        for(int i=0; i<word1.size(); i++){
            v[word1[i]-'a']++;
            v1[word2[i]-'a']++;
        }

        for(int i=0; i<26; i++){
            if((v[i] != 0 && v1[i] == 0) || (v[i] == 0 && v1[i] != 0)) return 0;
        }

        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());

        for(int i=0; i<26; i++){
            if(v[i] != v1[i]) return 0;
        }

        return 1;
    }
};
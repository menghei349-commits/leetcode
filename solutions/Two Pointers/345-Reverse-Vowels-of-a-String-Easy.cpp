class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        set<char> v{'a','e','i','o','u','A','E','I','O','U'};
        while(i < j){
            if(!v.count(s[i])) i++;
            if(!v.count(s[j])) j--;

            if(v.count(s[i]) && v.count(s[j])){
                swap(s[i], s[j]);
                i++, j--;
            }
        }

        return s;
    }
};
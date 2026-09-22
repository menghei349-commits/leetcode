class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = str1.size(), b = str2.size();
        int n = gcd(a, b);

        string ans = "";
        for(int i=0; i<n; i++){
            ans += str1[i];
        }

        bool check = 1;
        int i = 0;
        while(check && i < str1.size()){
            if(str1[i] != ans[i%ans.size()]){
                check = 0;
            }i++;
        }

        i = 0;
        while(check && i < str2.size()){
            if(str2[i] != ans[i%ans.size()]){
                check = 0;
            }i++;
        }

        if(check){
            return ans;
        }else{
            return "";
        }
    }
};
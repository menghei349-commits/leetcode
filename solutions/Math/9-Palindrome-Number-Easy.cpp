class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long int y = 0, q = x;
        while(q != 0){
            y *= 10;
            y += q%10;
            q /= 10;
        }

        if(x == y){
            return true;
        }else{
            return false;
        }
    }
};
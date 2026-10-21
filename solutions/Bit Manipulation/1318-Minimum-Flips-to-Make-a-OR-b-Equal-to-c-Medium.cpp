class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while (a != 0 || b != 0 || c != 0) {
            if (a % 2 == 1 && b % 2 == 1 && c % 2 == 0) {
                ans += 2;
            } else if ((a % 2 || b % 2) == c % 2) {
                ans += 0;
            } else {
                ans += 1;
            }

            a /= 2;
            b /= 2;
            c /= 2;
        }

        return ans;
    }
};
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int ans = -1;
    int guessNumber(int n) {
        BS(1, n);
        return ans;
    }

    void BS(int l, int r){
        if(l > r) return;
        int mid = l + (r - l) / 2;
        int g = guess(mid);
        if(g == 0){
            ans = mid;
            return;
        }
        if(g == -1) BS(l, mid - 1);
        else BS(mid + 1, r);
    }
};
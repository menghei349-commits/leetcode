class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<bool> v;
        v.push_back(0);
        v.insert(v.end(), flowerbed.begin(), flowerbed.end());
        v.push_back(0);

        for(int i=1; i<v.size()-1 && n != 0; i++){
            if(!(v[i-1] || v[i] || v[i+1])){
                v[i] = 1;
                n--;
            }
        }

        if(n == 0) return 1;
        else return 0;
    }
};
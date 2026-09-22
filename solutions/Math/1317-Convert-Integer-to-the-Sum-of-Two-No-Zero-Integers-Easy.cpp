class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> v;

        for(int i=1; i<n; i++){
            bool t = 1;
            int q = n-i, u = i;

            while(u != 0 && t){
                if(u % 10 == 0){
                    t = 0;
                    break;
                }u /= 10;
            }

            while(q != 0 && t){
                if(q % 10 == 0){
                    t = 0;
                    break;
                }q /= 10;
            }

            if(t){
                v.push_back(n-i);
                v.push_back(i);
                break;
            }
        }

        return v;
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i=0; i<=n; i++){
            int ans = 0, q = i;
            for(int j=pow(i, 0.5)+1; j>=0 && q != 0; j--){
                if(q >= pow(2, j)){
                    ans++;
                    q -= pow(2, j);
                }
            }

            v.push_back(ans);
        }

        return v;
    }
};
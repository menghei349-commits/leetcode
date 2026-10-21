class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int l = 0, r = products.size() - 1;
        
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            vector<string> v;
            
            while (l <= r && (products[l].size() <= i || products[l][i] != c)) l++;
            while (l <= r && (products[r].size() <= i || products[r][i] != c)) r--;
            
            for (int j = 0; j < 3 && l + j <= r; j++) {
                v.push_back(products[l + j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
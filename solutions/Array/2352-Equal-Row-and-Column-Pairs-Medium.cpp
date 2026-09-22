class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                for(int k=0; k<grid.size(); k++){
                    if(grid[i][k] != grid[k][j]){
                        break;
                    }

                    if(k == grid.size()-1){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
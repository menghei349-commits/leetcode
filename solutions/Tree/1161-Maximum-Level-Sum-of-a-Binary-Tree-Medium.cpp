/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    int maxLevelSum(TreeNode* root) {
        int ans = 0, Max = INT_MIN;
        solve(root, 0);

        for(int i=0; i<v.size(); i++){
            if (v[i] > Max) {
                Max = v[i];
                ans = i;
            }
        }

        return ans+1;
    }

    void solve(TreeNode* now, int d) {
        if (!now) return ;
        else if (d == v.size()) {
            v.push_back(now->val);
        }else {
            v[d] += now->val;
        }

        solve(now->right, d+1);
        solve(now->left, d+1);
    }
};
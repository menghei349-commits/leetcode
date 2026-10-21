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
    vector<int> rightSideView(TreeNode* root) {
        solve(0, root);

        return v;
    }

    void solve(int d,TreeNode* now) {
        if (!now) return ;
        else if (d == v.size()){
            v.push_back(now->val);
        }else{
            v[d] = now->val;
        }
        solve(d+1, now->left);
        solve(d+1, now->right);
    }
};
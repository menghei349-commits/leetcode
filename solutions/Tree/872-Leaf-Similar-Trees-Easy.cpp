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
    bool check = true;
    queue<int> v;

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        DFS(root1);
        solve(root2);
        return check && v.empty();
    }

    void DFS(TreeNode* now) {
        if (now->left == nullptr && now->right == nullptr) {
            v.push(now->val);
            return;
        }
        if (now->left != nullptr) DFS(now->left);
        if (now->right != nullptr) DFS(now->right);
    }

    void solve(TreeNode* now) {
        if (!check) return;
        if (now->left == nullptr && now->right == nullptr) {
            if (v.empty() || v.front() != now->val) {
                check = false;
            } else {
                v.pop();
            }
            return;
        }
        if (now->left != nullptr) solve(now->left);
        if (now->right != nullptr) solve(now->right);
    }
};
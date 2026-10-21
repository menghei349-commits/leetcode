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
    int ans = 0;
    int goodNodes(TreeNode* root) {
        int q = root->val;
        DFS(root, q);

        return ans;
    }

    void DFS(TreeNode* now, int q1){
        if(now->val >= q1) ans++;

        q1 = max(q1, now->val);
        if(now->right != nullptr) DFS(now->right, q1);
        if(now->left != nullptr) DFS(now->left, q1);
    }
};
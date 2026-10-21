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
    int maxDepth(TreeNode* root) {
        if(root != nullptr){
            DFS(root, 1);
        }

        return ans;
    }

    void DFS(TreeNode* now, int q){
        ans = max(ans, q);
        if(now->left != nullptr){
            DFS(now->left, q+1);
        }
        if(now->right != nullptr){
            DFS(now->right, q+1);
        }
    }
};
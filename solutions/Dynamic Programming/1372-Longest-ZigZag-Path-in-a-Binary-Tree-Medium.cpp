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
    int longestZigZag(TreeNode* root) {
        DFS(1, root, 0);
        DFS(2, root, 0);

        return ans;
    }

    void DFS(int pos, TreeNode* now, int deep){
        if (!now) return;
        ans = max(ans, deep);

        if(pos == 1){
            DFS(1, now->left, 1);
            DFS(2, now->right, deep+1);
        }else{
            DFS(1, now->left, deep+1);
            DFS(2, now->right, 1);
        }
    }
};
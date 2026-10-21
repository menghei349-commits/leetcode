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
    unordered_map<long long, int> v;
    
    int pathSum(TreeNode* root, int targetSum) {
        v[0] = 1;
        solve(root, 0, targetSum);
        return ans;
    }
    
    void solve(TreeNode* now, long long sum, int targetSum) {
        if (!now) return;
        sum += now->val;
        
        if (v.count(sum - targetSum)) {
            ans += v[sum - targetSum];
        }
        
        v[sum]++;
        solve(now->left, sum, targetSum);
        solve(now->right, sum, targetSum);
        v[sum]--;
    }
};
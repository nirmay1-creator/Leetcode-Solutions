class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
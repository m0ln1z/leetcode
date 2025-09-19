class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;

        path.push_back(node->val);
        targetSum -= node->val;

        // Если лист и сумма совпала
        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(path);
        }

        dfs(node->left, targetSum, path, result);
        dfs(node->right, targetSum, path, result);

        path.pop_back(); // backtrack
    }
};

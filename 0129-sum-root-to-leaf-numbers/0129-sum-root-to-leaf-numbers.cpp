class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (!node) return 0;

        current = current * 10 + node->val;

        // если лист — вернуть накопленное число
        if (!node->left && !node->right)
            return current;

        // рекурсивно спускаемся по детям
        return dfs(node->left, current) + dfs(node->right, current);
    }
};

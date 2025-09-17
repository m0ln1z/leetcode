class Solution {
public:
    unordered_map<int, int> inorderIndex; // значение -> индекс в inorder
    int postorderIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;

        // сохраняем индексы inorder для O(1) поиска
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        // берем текущий корень из postorder
        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // индекс корня в inorder
        int mid = inorderIndex[rootVal];

        // важно: сначала строим ПРАВОЕ поддерево, потом ЛЕВОЕ
        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }
};

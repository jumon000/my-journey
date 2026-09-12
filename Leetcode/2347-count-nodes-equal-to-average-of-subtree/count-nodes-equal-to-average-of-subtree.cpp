class Solution {
public:
    int ans = 0;

    pair<int,int> solve(TreeNode* node) {
        if (!node) return {0, 0};

        pair<int,int> left = solve(node->left);
        pair<int,int> right = solve(node->right);

        int sum = left.first + right.first + node->val;
        int cnt = left.second + right.second + 1;

        if (sum / cnt == node->val) {
            ans++;
        }

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
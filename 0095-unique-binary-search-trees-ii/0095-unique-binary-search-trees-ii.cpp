class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<vector<vector<TreeNode*>>> memo(
            n + 2, vector<vector<TreeNode*>>(n + 2)
        );
        return build(1, n, memo);
    }

private:
    vector<TreeNode*> build(int start, int end, 
                            vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) return {nullptr};
        if (!memo[start][end].empty()) return memo[start][end];

        vector<TreeNode*> trees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = build(start, i - 1, memo);
            vector<TreeNode*> rightTrees = build(i + 1, end, memo);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    trees.push_back(new TreeNode(i, left, right));
                }
            }
        }
        return memo[start][end] = trees;
    }
};

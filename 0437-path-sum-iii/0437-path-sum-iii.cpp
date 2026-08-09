class Solution {
public:
    unordered_map<long long, int> mp;

    int dfs(TreeNode* root, long long sum, int targetSum) {
        if (root == NULL)
            return 0;

        sum += root->val;

        // Kitne previous prefix sums hain
        // jisse current path ka sum target banega
        int count = mp[sum - targetSum];

        // Current prefix sum store karo
        mp[sum]++;

        count += dfs(root->left, sum, targetSum);
        count += dfs(root->right, sum, targetSum);

        // Backtracking
        mp[sum]--;

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;

        return dfs(root, 0, targetSum);
    }
};
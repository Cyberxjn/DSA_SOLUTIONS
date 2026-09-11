class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode* root, int k, unordered_set<int>& seen) {
        if (!root) return false;
        
        // Check if the complement exists in the set
        if (seen.count(k - root->val)) return true;
        
        // Add the current value to the set
        seen.insert(root->val);
        
        // Recurse for left and right subtrees
        return dfs(root->left, k, seen) || dfs(root->right, k, seen);
    }
};

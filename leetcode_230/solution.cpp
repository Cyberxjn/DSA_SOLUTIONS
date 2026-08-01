class Solution {
public:
    int ans = -1;
    int cnt = 0;

    void inorder(TreeNode* root, int k) {
        if (!root || cnt >= k) return;

        inorder(root->left, k);

        cnt++;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};

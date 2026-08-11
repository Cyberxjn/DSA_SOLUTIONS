class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Node nahi mili
        if (root == NULL)
            return NULL;

        // Left subtree mein search
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Right subtree mein search
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Node mil gayi
        else {

            // 0 child
            if (root->left == NULL && root->right == NULL)
                return NULL;

            // Only right child
            if (root->left == NULL)
                return root->right;

            // Only left child
            if (root->right == NULL)
                return root->left;

            // 2 children
            TreeNode* temp = root->right;

            // Right subtree ka smallest
            while (temp->left != NULL)
                temp = temp->left;

            // Value copy
            root->val = temp->val;

            // Duplicate node delete
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
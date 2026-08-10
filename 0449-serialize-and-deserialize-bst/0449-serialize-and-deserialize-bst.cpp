class Codec {
public:

    // Serialize: BST -> string
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        string ans;

        function<void(TreeNode*)> preorder = [&](TreeNode* node) {
            if (node == nullptr)
                return;

            ans += to_string(node->val) + " ";

            preorder(node->left);
            preorder(node->right);
        };

        preorder(root);

        ans.pop_back(); // remove last space
        return ans;
    }


    // Deserialize: string -> BST
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<int> nums;
        stringstream ss(data);
        int x;

        while (ss >> x)
            nums.push_back(x);

        int index = 0;

        function<TreeNode*(int, int)> build =
            [&](int low, int high) -> TreeNode* {

                if (index == nums.size())
                    return nullptr;

                int value = nums[index];

                // value doesn't belong to this range
                if (value < low || value > high)
                    return nullptr;

                index++;

                TreeNode* root = new TreeNode(value);

                root->left = build(low, value);
                root->right = build(value, high);

                return root;
            };

        return build(INT_MIN, INT_MAX);
    }
};
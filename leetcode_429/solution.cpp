class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            vector<int> level;

            // Current level ke nodes
            for (int i = 0; i < size; i++) {

                Node* node = q.front();
                q.pop();

                level.push_back(node->val);

                // Saare children queue me daalo
                for (Node* child : node->children) {
                    q.push(child);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};

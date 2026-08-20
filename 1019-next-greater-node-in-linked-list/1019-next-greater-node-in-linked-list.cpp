class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> nums;

        // Linked List → Array
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(nums.size(), 0);
        stack<int> st;

        // Right to Left
        for (int i = nums.size() - 1; i >= 0; i--) {

            // Smaller/equal elements useless hain
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // Stack top = next greater
            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(nums[i]);
        }

        return ans;
    }
};
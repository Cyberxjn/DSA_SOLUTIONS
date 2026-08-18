class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        // 1. Count total nodes
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        // 2. Size of each part
        int size = n / k;

        // 3. Extra nodes
        int extra = n % k;

        vector<ListNode*> ans(k);

        temp = head;

        for (int i = 0; i < k; i++) {

            ans[i] = temp;

            // Current part size
            int partSize = size;

            // First 'extra' parts get 1 extra node
            if (extra > 0) {
                partSize++;
                extra--;
            }

            // Move to last node of current part
            for (int j = 1; j < partSize && temp; j++) {
                temp = temp->next;
            }

            // Break the linked list
            if (temp) {
                ListNode* nextPart = temp->next;
                temp->next = nullptr;
                temp = nextPart;
            }
        }

        return ans;
    }
};
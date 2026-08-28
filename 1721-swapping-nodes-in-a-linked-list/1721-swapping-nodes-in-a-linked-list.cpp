class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;

        // Find kth node from beginning
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Move temp k nodes ahead
        temp = first->next;

        // Find kth node from end
        while (temp != NULL) {
            temp = temp->next;
            second = second->next;
        }

        // Swap values
        int x = first->val;
        first->val = second->val;
        second->val = x;

        return head;
    }
};
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;

        int sum = 0;
        ListNode* temp = dummy;

        // First pass
        while (temp != NULL) {
            sum += temp->val;
            mp[sum] = temp;
            temp = temp->next;
        }

        // Second pass
        sum = 0;
        temp = dummy;

        while (temp != NULL) {
            sum += temp->val;
            temp->next = mp[sum]->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
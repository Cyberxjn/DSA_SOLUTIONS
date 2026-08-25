class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* before = list1;

        for(int i = 0; i < a - 1; i++) {
            before = before->next;
        }

        ListNode* after = before;

        for(int i = 0; i <= b - a + 1; i++) {
            after = after->next;
        }

        ListNode* last = list2;

        while(last->next != NULL) {
            last = last->next;
        }

        before->next = list2;
        last->next = after;

        return list1;
    }
};
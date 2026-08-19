class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end());
        
        int ans = 0;
        
        while (head) {
            
            // Current node nums me hai
            // aur next node nums me nahi hai
            if (st.count(head->val) &&
                (head->next == NULL || !st.count(head->next->val))) {
                
                ans++;
            }
            
            head = head->next;
        }
        
        return ans;
    }
};
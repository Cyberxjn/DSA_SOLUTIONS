class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Phase 1: Find the intersection point of the two pointers
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];          // Move 1 step
            fast = nums[nums[fast]];    // Move 2 steps
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle (the duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];          // Move 1 step
            fast = nums[fast];          // Move 1 step
        }
        
        return slow;
    }
};

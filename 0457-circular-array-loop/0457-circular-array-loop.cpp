#include <vector>

class Solution {
private:
    // Helper function to calculate the next index with proper wrap-around
    int getNext(const std::vector<int>& nums, int i, int n) {
        int nextIndex = (i + nums[i]) % n;
        return nextIndex >= 0 ? nextIndex : nextIndex + n;
    }

public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;

        for (int i = 0; i < n; ++i) {
            // 0 means it's either visited and invalid, or an processed element
            if (nums[i] == 0) continue;

            int slow = i;
            int fast = i;

            // Ensure the fast pointer moves in the same direction as the starting point
            // nums[i] * nums[next] > 0 guarantees matching directions (both positive or both negative)
            while (nums[i] * nums[getNext(nums, slow, n)] > 0 &&
                   nums[i] * nums[getNext(nums, fast, n)] > 0 &&
                   nums[i] * nums[getNext(nums, getNext(nums, fast, n), n)] > 0) {
                
                slow = getNext(nums, slow, n);
                fast = getNext(nums, getNext(nums, fast, n), n);

                if (slow == fast) {
                    // Check if it's a single-element loop (invalid per rules)
                    if (slow == getNext(nums, slow, n)) {
                        break; 
                    }
                    return true;
                }
            }

            // Optimization: If no cycle was found, clear the path traversed to avoid re-evaluation
            slow = i;
            int currentSign = nums[i];
            while (currentSign * nums[slow] > 0) {
                int nextNode = getNext(nums, slow, n);
                nums[slow] = 0; 
                slow = nextNode;
            }
        }

        return false;
    }
};

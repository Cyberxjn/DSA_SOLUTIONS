#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = -2; // Initialized so that end - start + 1 = 0 if sorted
        
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        
        // Single pass can handle both, or two clean loops:
        for (int i = 0; i < n; i++) {
            // Track max from left to right
            max_val = std::max(max_val, nums[i]);
            if (nums[i] < max_val) {
                end = i;
            }
            
            // Track min from right to left
            int j = n - 1 - i;
            min_val = std::min(min_val, nums[j]);
            if (nums[j] > min_val) {
                start = j;
            }
        }
        
        return end - start + 1;
    }
};

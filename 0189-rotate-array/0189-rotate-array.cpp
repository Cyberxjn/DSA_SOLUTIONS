#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is greater than array size
        
        // Step 1: Reverse the whole array
        std::reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);
        
        // Step 3: Reverse the remaining elements
        std::reverse(nums.begin() + k, nums.end());
    }
};

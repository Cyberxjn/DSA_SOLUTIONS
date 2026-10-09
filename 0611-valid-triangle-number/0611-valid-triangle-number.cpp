#include <vector>
#include <algorithm>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Step 1: Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Fix the largest side 'c' from right to left
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;
            int right = i - 1;
            
            // Step 3: Two-pointer scan for the remaining two sides
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // If valid, all elements between left and right work with nums[right] and nums[i]
                    count += (right - left);
                    right--; // Move right pointer to check smaller pairs
                } else {
                    left++; // Sum is too small, increase the smaller side
                }
            }
        }
        
        return count;
    }
};

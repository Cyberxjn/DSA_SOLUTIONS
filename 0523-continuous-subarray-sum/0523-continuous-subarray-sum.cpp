#include <vector>
#include <unordered_map>

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        // Map to store the first occurrence of a remainder: {remainder, index}
        std::unordered_map<int, int> remainder_map;
        
        // Initialize with remainder 0 at index -1 to handle subarrays starting from index 0
        remainder_map[0] = -1;
        
        int running_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            running_sum += nums[i];
            
            // Calculate the remainder when divided by k
            int remainder = running_sum % k;
            
            // Handle negative remainders if nums could contain negative numbers
            if (remainder < 0) {
                remainder += k;
            }
            
            // If the remainder has been seen before
            if (remainder_map.count(remainder)) {
                // Check if the subarray length is at least 2
                if (i - remainder_map[remainder] >= 2) {
                    return true;
                }
            } else {
                // Store the index of the first time we see this remainder
                remainder_map[remainder] = i;
            }
        }
        
        return false;
    }
};

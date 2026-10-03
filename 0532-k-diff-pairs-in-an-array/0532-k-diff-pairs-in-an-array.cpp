#include <vector>
#include <unordered_map>

class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        // Absolute difference cannot be negative
        if (k < 0) return 0;
        
        // Count frequencies of each number
        std::unordered_map<int, int> num_counts;
        for (int num : nums) {
            num_counts[num]++;
        }
        
        int pair_count = 0;
        
        // Iterate through unique elements
        for (const auto& [x, count] : num_counts) {
            if (k > 0) {
                // For k > 0, check if the complement (x + k) exists
                if (num_counts.find(x + k) != num_counts.end()) {
                    pair_count++;
                }
            } else {
                // For k == 0, check if the number appears 2 or more times
                if (count >= 2) {
                    pair_count++;
                }
            }
        }
        
        return pair_count;
    }
};

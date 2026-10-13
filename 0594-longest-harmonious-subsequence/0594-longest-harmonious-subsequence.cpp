#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        
        // Step 1: Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_length = 0;
        
        // Step 2: Find pairs of (x, x + 1) and calculate combined frequencies
        for (const auto& [num, count] : freq) {
            auto it = freq.find(num + 1);
            if (it != freq.end()) {
                max_length = std::max(max_length, count + it->second);
            }
        }
        
        return max_length;
    }
};

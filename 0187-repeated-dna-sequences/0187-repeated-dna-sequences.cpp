#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::vector<std::string> result;
        
        // If the string length is less than 10, no 10-letter sequence can repeat
        if (s.length() < 10) {
            return result;
        }
        
        std::unordered_map<std::string, int> counts;
        
        // Slide a window of size 10 across the string
        for (int i = 0; i <= s.length() - 10; ++i) {
            std::string sub = s.substr(i, 10);
            counts[sub]++;
        }
        
        // Collect all sequences that appeared more than once
        for (const auto& pair : counts) {
            if (pair.second > 1) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }
};

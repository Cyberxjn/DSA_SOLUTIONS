#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int n = s.length();
        
        // Move in steps of 2k
        for (int i = 0; i < n; i += 2 * k) {
            // Find the end point for reversal: either i + k, or the end of the string
            int end = std::min(i + k, n);
            
            // Reverse the first k characters in the current 2k block
            std::reverse(s.begin() + i, s.begin() + end);
        }
        
        return s;
    }
};

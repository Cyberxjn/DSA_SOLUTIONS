#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        int n = s.length();
        std::vector<int> ans(n);
        
        // Step 1: Left-to-Right Pass
        // Initialize position to a large negative index to handle characters before the first occurrence of 'c'
        int c_pos = -n; 
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                c_pos = i;
            }
            ans[i] = i - c_pos;
        }
        
        // Step 2: Right-to-Left Pass
        // Initialize position to a large positive index to handle characters after the last occurrence of 'c'
        c_pos = 2 * n; 
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                c_pos = i;
            }
            ans[i] = std::min(ans[i], c_pos - i);
        }
        
        return ans;
    }
};

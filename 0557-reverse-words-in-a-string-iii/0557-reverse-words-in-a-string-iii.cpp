#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int left = 0;
        int n = s.length();
        
        for (int right = 0; right <= n; ++right) {
            // If we reach a space or the end of the string, we have found a word boundary
            if (right == n || s[right] == ' ') {
                // Reverse the word in place using standard library pointers/iterators
                std::reverse(s.begin() + left, s.begin() + right);
                // Move the left pointer to the start of the next word
                left = right + 1;
            }
        }
        
        return s;
    }
};

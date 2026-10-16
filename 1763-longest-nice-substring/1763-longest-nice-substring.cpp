#include <string>
#include <unordered_set>
#include <cctype>

class Solution {
public:
    std::string longestNiceSubstring(std::string s) {
        // A nice string must have a length of at least 2
        if (s.length() < 2) return "";
        
        // Put all characters in a set for O(1) lookups
        std::unordered_set<char> seen(s.begin(), s.end());
        
        // Find a character that breaks the "nice" condition
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            
            // If the matching upper/lowercase counterpart is missing, 
            // this character cannot be part of any nice substring.
            if (seen.find(std::isupper(c) ? std::tolower(c) : std::toupper(c)) == seen.end()) {
                // Split the problem into left and right substrings
                std::string left = longestNiceSubstring(s.substr(0, i));
                std::string right = longestNiceSubstring(s.substr(i + 1));
                
                // Return the longer nice substring (or the earliest if tied)
                return left.length() >= right.length() ? left : right;
            }
        }
        
        // If the entire string passes, then it is inherently nice
        return s;
    }
};

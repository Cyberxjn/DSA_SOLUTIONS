#include <string>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int writeIdx = 0; // Tracks where to write the next character
        
        for (int i = 0; i < n; i++) {
            // Skip leading or intermediate spaces
            if (s[i] == ' ') continue;
            
            // Add a single space before subsequent words
            if (writeIdx > 0) {
                s[writeIdx++] = ' ';
            }
            
            // Find the end of the current word
            int start = writeIdx;
            while (i < n && s[i] != ' ') {
                s[writeIdx++] = s[i++];
            }
            
            // Reverse the current word back to its original order
            reverse(s.begin() + start, s.begin() + writeIdx);
        }
        
        // Resize the string to remove trailing junk characters
        s.resize(writeIdx);
        return s;
    }
};

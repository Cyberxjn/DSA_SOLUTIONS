#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int nextGreaterElement(int n) {
        // Convert the number to a string to easily manipulate digits
        std::string s = std::to_string(n);
        int len = s.length();
        
        // Step 1: Find the first decreasing digit from the right
        int i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        // If no such digit is found, the digits are in descending order
        // which means no greater permutation is possible.
        if (i < 0) return -1;
        
        // Step 2: Find the smallest digit to the right of 'i' that is greater than s[i]
        int j = len - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        
        // Step 3: Swap digits at index i and j
        std::swap(s[i], s[j]);
        
        // Step 4: Reverse the digits after index i to get the smallest possible sequence
        std::reverse(s.begin() + i + 1, s.end());
        
        // Convert the string back to a long long to check for 32-bit integer overflow
        long long result = std::stoll(s);
        
        return (result > INT_MAX) ? -1 : static_cast<int>(result);
    }
};

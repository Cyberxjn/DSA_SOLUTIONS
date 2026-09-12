#include <string>

class Solution {
private:
    // Helper function to check if a substring is a pure palindrome
    bool isPalindromeRange(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                // If a mismatch is found, try skipping either the left character or the right character
                return isPalindromeRange(s, left + 1, right) || isPalindromeRange(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        return true; // Already a palindrome without any deletions
    }
};

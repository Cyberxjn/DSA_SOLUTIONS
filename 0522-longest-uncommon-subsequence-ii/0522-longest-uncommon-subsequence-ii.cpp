#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    // Helper function to check if string 's' is a subsequence of string 't'
    bool isSubsequence(const std::string& s, const std::string& t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }

public:
    int findLUSlength(std::vector<std::string>& strs) {
        int maxLength = -1;
        int n = strs.size();
        
        for (int i = 0; i < n; ++i) {
            bool isUncommon = true;
            for (int j = 0; j < n; ++j) {
                // Do not check a string against itself
                if (i == j) continue;
                
                // If strs[i] is found inside strs[j], it cannot be an uncommon subsequence
                if (isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            // If it's truly uncommon, try to maximize our answer
            if (isUncommon) {
                maxLength = std::max(maxLength, static_cast<int>(strs[i].length()));
            }
        }
        
        return maxLength;
    }
};

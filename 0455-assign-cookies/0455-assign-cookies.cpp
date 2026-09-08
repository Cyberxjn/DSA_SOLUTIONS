#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        // Sort both the greed factors and cookie sizes
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int childPointer = 0;
        int cookiePointer = 0;
        
        // Iterate through both arrays
        while (childPointer < g.size() && cookiePointer < s.size()) {
            // If the cookie can satisfy the child, move to the next child
            if (s[cookiePointer] >= g[childPointer]) {
                childPointer++;
            }
            // Always move to the next cookie
            cookiePointer++;
        }
        
        // The number of content children is represented by childPointer
        return childPointer;
    }
};

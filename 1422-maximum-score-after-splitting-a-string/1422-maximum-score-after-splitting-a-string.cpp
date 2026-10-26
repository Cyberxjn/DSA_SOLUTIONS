#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zeros = 0; // Fixed typo (removed 'e')
        int ones = 0;
        int max_diff = INT_MIN; // Changed min_diff to INT_MIN
        
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '0') { // Removed stray semicolon
                zeros++;
            } else {
                ones++;
            }
            // Moved inside the loop body
            max_diff = std::max(max_diff, zeros - ones);
        } // Loop ends here
        
        if(s.back() == '1') {
            ones++;
        }
        
        return max_diff + ones;
    } // Function ends here
};

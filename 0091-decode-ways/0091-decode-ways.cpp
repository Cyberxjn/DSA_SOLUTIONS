#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev2 = 1; // Represents dp[i - 2] (empty string base case)
        int prev1 = 1; // Represents dp[i - 1] (first valid character)

        for (int i = 1; i < s.length(); ++i) {
            int current = 0;

            // 1. Single-digit check (1 to 9)
            if (s[i] != '0') {
                current += prev1;
            }

            // 2. Two-digit check (10 to 26)
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            // Shift states forward
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

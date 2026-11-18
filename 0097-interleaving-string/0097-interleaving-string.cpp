#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        // Base length check
        if (m + n != s3.length()) {
            return false;
        }
        
        // Ensure s2 is the shorter string to minimize space to O(min(m, n))
        if (m < n) {
            swap(s1, s2);
            swap(m, n);
        }
        
        vector<bool> dp(n + 1, false);
        
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else if (i == 0) {
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
                } else if (j == 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[i - 1]);
                } else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || 
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return dp[n];
    }
};

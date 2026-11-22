class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        
        // Find the longest word to bound our inner loop
        int maxLen = 0;
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }

        // dp[i] is true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            // Check substrings ending at i-1, up to maxLen characters back
            for (int j = i - 1; j >= max(0, i - maxLen); j--) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; 
                }
            }
        }

        return dp[n];
    }
};

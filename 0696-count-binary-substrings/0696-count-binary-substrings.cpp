class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev = 0; // Length of the previous consecutive group
        int curr = 1; // Length of the current consecutive group
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        // Add the valid substrings from the last two groups
        ans += min(prev, curr);
        
        return ans;
    }
};

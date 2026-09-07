class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        
        int sPtr = 0;
        for (int tPtr = 0; tPtr < t.length(); ++tPtr) {
            if (s[sPtr] == t[tPtr]) {
                sPtr++;
                if (sPtr == s.length()) return true;
            }
        }
        
        return false;
    }
};

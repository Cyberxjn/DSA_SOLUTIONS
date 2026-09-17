class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        int skipS = 0; // Tracks backspaces needed for string s
        int skipT = 0; // Tracks backspaces needed for string t
        
        while (i >= 0 || j >= 0) {
            // Find the next valid character in string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            // Find the next valid character in string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            // If both characters are valid, compare them
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                // If one string reaches the end but the other doesn't
                if ((i >= 0) != (j >= 0)) {
                    return false;
                }
            }
            
            i--;
            j--;
        }
        
        return true;
    }
};

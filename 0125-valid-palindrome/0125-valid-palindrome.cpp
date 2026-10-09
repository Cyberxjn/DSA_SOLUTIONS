
class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";

        // Sirf letters aur numbers rakho
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                p += tolower(s[i]);
            }
        }

        // Reverse string
        string rev = "";
        for (int i = 0; i < p.size(); i++) {
            rev.insert(rev.begin(), p[i]);
        }

        // Compare
        if (p == rev) {
            return true;
        } else {
            return false;
        }
    }
};
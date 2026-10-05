class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // If s1 is longer than s2, a permutation cannot be a substring
        if (n1 > n2) return false;
        
        // Frequency arrays for lowercase English letters
        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);
        
        // Count frequencies for s1 and the first window of s2
        for (int i = 0; i < n1; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }
        
        // If the initial window matches, return true
        if (s1Count == windowCount) return true;
        
        // Slide the window across s2
        for (int i = n1; i < n2; i++) {
            // Include the new character entering the window
            windowCount[s2[i] - 'a']++;
            // Exclude the old character leaving the window
            windowCount[s2[i - n1] - 'a']--;
            
            // Check if the current window matches s1's frequency
            if (s1Count == windowCount) {
                return true;
            }
        }
        
        return false;
    }
};

#include <string>
#include <vector>

class Solution {
public:
    std::string findLongestWord(std::string s, std::vector<std::string>& dictionary) {
        std::string longest_word = "";
        
        for (const std::string& word : dictionary) {
            // Early pruning: skip if the word is shorter than the current max length
            if (word.length() < longest_word.length()) continue;
            
            // Skip if length is equal but the word is lexicographically larger
            if (word.length() == longest_word.length() && word >= longest_word) continue;
            
            // Check if the current word is a valid subsequence of s
            if (isSubsequence(s, word)) {
                longest_word = word;
            }
        }
        
        return longest_word;
    }

private:
    bool isSubsequence(const std::string& s, const std::string& word) {
        int s_idx = 0, word_idx = 0;
        int s_len = s.length(), word_len = word.length();
        
        // Two-pointer matching
        while (s_idx < s_len && word_idx < word_len) {
            if (s[s_idx] == word[word_idx]) {
                word_idx++;
            }
            s_idx++;
        }
        
        // Returns true if the entire word was matched
        return word_idx == word_len;
    }
};

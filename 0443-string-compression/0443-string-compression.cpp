#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; // Pointer to write the compressed characters
        int i = 0;     // Pointer to read through the array
        
        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;
            
            // Count occurrences of the current character
            while (i < chars.size() && chars[i] == currentChar) {
                count++;
                i++;
            }
            
            // Write the character
            chars[write++] = currentChar;
            
            // If the character repeats, write the count digits
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write; // Returns the new length of the compressed array
    }
};

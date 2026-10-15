#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        int n = code.size();
        std::vector<int> result(n, 0);
        
        // Base case: If k is 0, the elements are replaced by 0 (already initialized)
        if (k == 0) return result;
        
        // Define the initial window bounds based on the sign of k
        int start = (k > 0) ? 1 : n + k;
        int end = (k > 0) ? k : n - 1;
        
        // Calculate the sum of the first window
        int windowSum = 0;
        for (int i = start; i <= end; ++i) {
            windowSum += code[i];
        }
        
        // Slide the window across the array
        for (int i = 0; i < n; ++i) {
            result[i] = windowSum;
            
            // Slide window forward: subtract old start, add new end
            windowSum -= code[start % n];
            start++;
            end++;
            windowSum += code[end % n];
        }
        
        return result;
    }
};

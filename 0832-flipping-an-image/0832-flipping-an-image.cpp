#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        int n = image.size();
        
        for (int i = 0; i < n; ++i) {
            int left = 0;
            int right = n - 1;
            
            while (left <= right) {
                if (left == right) {
                    // Middle element in an odd-length row only needs inversion
                    image[i][left] ^= 1;
                } else if (image[i][left] == image[i][right]) {
                    // If elements are the same, they stay in position after flipping, 
                    // so we just invert both.
                    image[i][left] ^= 1;
                    image[i][right] ^= 1;
                }
                // If elements are different (e.g., 0 and 1), flipping them 
                // and then inverting them results in the exact same values. 
                // So we do nothing if they are different.
                
                left++;
                right--;
            }
        }
        
        return image;
    }
};

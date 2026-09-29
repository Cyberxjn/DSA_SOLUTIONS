#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        // Step 1: Sort the heaters to enable binary search
        std::sort(heaters.begin(), heaters.end());
        
        int minRadius = 0;
        
        // Step 2: Find the distance to the closest heater for each house
        for (int house : houses) {
            // Find the first heater positioned at or after the current house
            auto it = std::lower_bound(heaters.begin(), heaters.end(), house);
            
            int currentHouseDist = INT_MAX;
            
            // Distance to the heater on the right (if it exists)
            if (it != heaters.end()) {
                currentHouseDist = std::min(currentHouseDist, *it - house);
            }
            
            // Distance to the heater on the left (if it exists)
            if (it != heaters.begin()) {
                currentHouseDist = std::min(currentHouseDist, house - *(it - 1));
            }
            
            // The required radius must be large enough to cover this house
            minRadius = std::max(minRadius, currentHouseDist);
        }
        
        return minRadius;
    }
};

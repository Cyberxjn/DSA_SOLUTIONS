#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        // Calculate the sum of the first window of size k
        double current_sum = std::accumulate(nums.begin(), nums.begin() + k, 0.0);
        double max_sum = current_sum;
        
        // Slide the window across the rest of the array
        for (int i = k; i < nums.size(); ++i) {
            current_sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, current_sum);
        }
        
        // Return the maximum average
        return max_sum / k;
    }
};

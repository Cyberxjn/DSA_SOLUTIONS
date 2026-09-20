#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Sort the array to use two pointers and easily skip duplicates
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Optimization 1: Smallest possible sum from this point exceeds target
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            // Optimization 2: Largest possible sum from this point cannot reach target
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Optimization 3: Smallest possible sum from this point exceeds target
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                // Optimization 4: Largest possible sum from this point cannot reach target
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                // Two-pointer approach for the remaining two elements
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

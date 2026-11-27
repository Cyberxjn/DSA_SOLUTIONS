#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to solve the standard linear House Robber problem
    int robLinear(const vector<int>& nums, int start, int end) {
        int prevTwo = 0; // Max money 2 houses back
        int prevOne = 0; // Max money 1 house back

        for (int i = start; i <= end; ++i) {
            int current = max(prevOne, prevTwo + nums[i]);
            prevTwo = prevOne;
            prevOne = current;
        }

        return prevOne;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge case: only one house to rob
        if (n == 1) {
            return nums[0];
        }

        // Case 1: Exclude the last house
        int maxExcludingLast = robLinear(nums, 0, n - 2);
        
        // Case 2: Exclude the first house
        int maxExcludingFirst = robLinear(nums, 1, n - 1);

        return max(maxExcludingLast, maxExcludingFirst);
    }
};

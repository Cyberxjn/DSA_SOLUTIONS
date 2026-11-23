
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            // A negative number turns the smallest product into the largest
            if (num < 0) {
                swap(currMax, currMin);
            }

            // Either start a new subarray at num, or extend the existing one
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);

            // Update the global maximum
            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};

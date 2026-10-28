#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 1);
        
        // Step 1: Calculate prefix products and store them in ans
        // ans[i] will contain the product of all elements to the left of i
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        // Step 2: Calculate suffix products on the fly and multiply with prefix products
        // right_product keeps track of the product of all elements to the right of i
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }
        
        return ans;
    }
};

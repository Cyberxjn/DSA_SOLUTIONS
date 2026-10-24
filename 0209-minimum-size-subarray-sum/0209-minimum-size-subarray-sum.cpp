class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int l = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r]; // Expand the window to the right
            
            while (sum >= target) { // Contract the window from the left
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        
        return ans == INT_MAX ? 0 : ans; // Return 0 if no valid subarray found
    }
};

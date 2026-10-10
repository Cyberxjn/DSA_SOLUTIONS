class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = 1;

        while (high < nums.size()) {
            if (nums[low] > nums[high]) {
                swap(nums[low], nums[high]);
                low = 0;
                high = 1;
            } else {
                low++;
                high++;
            }
        }
    }
};

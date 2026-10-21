class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        int head = 0;
        int tail = nums.size() - 1;
        for (int pos = nums.size() - 1; pos >= 0; pos--) {
            if (nums[head] > nums[tail]) {
                result[pos] = nums[head];
                head++;
            } else {
                result[pos] = nums[tail];
                tail--;
            }
        }
        return result;
    }
};
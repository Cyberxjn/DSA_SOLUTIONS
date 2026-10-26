class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minsum = 0;
       for(int i =0; i< nums.size(); i++){
        sum+=nums[i];
        minsum= min (minsum,sum);
       }return 1-minsum;
    }
};
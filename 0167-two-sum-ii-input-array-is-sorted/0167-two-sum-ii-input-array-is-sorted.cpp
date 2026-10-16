class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ind1 = 0;
        int ind2 = numbers.size()-1;
        for (int i = 1; i<numbers.size(); i++){
            int val = numbers[ind1] + numbers[ind2];
            if (val < target){
                ind1++;
            }else if(val > target){
                ind2--;
            }else if(val == target){
                return {ind1+1 , ind2 +1};
            }
        }return {};
    } 
};
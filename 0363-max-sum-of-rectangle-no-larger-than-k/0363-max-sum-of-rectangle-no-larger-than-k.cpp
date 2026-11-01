#include <vector>
#include <set>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSumSubmatrix(std::vector<std::vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSum = INT_MIN;
        
        // Optimize by scanning along the smaller dimension
        bool rowIsSmaller = (m < n);
        int outerLimit = rowIsSmaller ? m : n;
        int innerLimit = rowIsSmaller ? n : m;
        
        for (int i = 0; i < outerLimit; ++i) {
            // Compressed array to store 1D projection of the 2D matrix
            std::vector<int> compressedRowOrCol(innerLimit, 0);
            
            for (int j = i; j < outerLimit; ++j) {
                for (int c = 0; c < innerLimit; ++c) {
                    // Accumulate matrix values into our 1D array
                    compressedRowOrCol[c] += rowIsSmaller ? matrix[j][c] : matrix[c][j];
                }
                
                // Find the maximum subarray sum <= k using an ordered set (std::set)
                std::set<int> prefixSums;
                prefixSums.insert(0);
                int currentPrefixSum = 0;
                
                for (int sum : compressedRowOrCol) {
                    currentPrefixSum += sum;
                    
                    // We need: currentPrefixSum - pastPrefixSum <= k
                    // Rearranging gives: pastPrefixSum >= currentPrefixSum - k
                    auto it = prefixSums.lower_bound(currentPrefixSum - k);
                    
                    if (it != prefixSums.end()) {
                        maxSum = std::max(maxSum, currentPrefixSum - *it);
                    }
                    
                    // Early exit optimization if we match target exactly
                    if (maxSum == k) return k; 
                    
                    prefixSums.insert(currentPrefixSum);
                }
            }
        }
        
        return maxSum;
    }
};

#include <vector>
#include <cstdlib>
#include <algorithm>

class Solution {
private:
    std::vector<std::vector<int>> rects;
    std::vector<int> prefix_sums;
    int total_points;

public:
    Solution(std::vector<std::vector<int>>& rects) {
        this->rects = rects;
        total_points = 0;
        
        for (const auto& rect : rects) {
            // Number of integer points in the current inclusive rectangle
            long long width = (long long)rect[2] - rect[0] + 1;
            long long height = (long long)rect[3] - rect[1] + 1;
            total_points += (width * height);
            prefix_sums.push_back(total_points);
        }
    }
    
    std::vector<int> pick() {
        // Pick a random point index from 1 to total_points
        int target = rand() % total_points + 1;
        
        // Binary search to find which rectangle contains this point index
        auto it = std::lower_bound(prefix_sums.begin(), prefix_sums.end(), target);
        int rect_idx = std::distance(prefix_sums.begin(), it);
        
        // Get the coordinates of the chosen rectangle
        const auto& rect = rects[rect_idx];
        int x1 = rect[0], y1 = rect[1];
        int x2 = rect[2], y2 = rect[3];
        
        // Randomly choose an offset within the selected rectangle
        int rand_x = x1 + rand() % (x2 - x1 + 1);
        int rand_y = y1 + rand() % (y2 - y1 + 1);
        
        return {rand_x, rand_y};
    }
};

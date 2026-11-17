#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // i >> 1 is i / 2 (removes the last bit)
            // i & 1 checks if the last bit is 1 or 0
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};

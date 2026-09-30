class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1; // "122" contains one '1'

        // Pre-allocate vector size to avoid dynamic resizing overheads
        vector<int> v(n + 1);
        v[0] = 1;
        v[1] = 2;
        v[2] = 2;

        int head = 2;  // Pointer to read the group size
        int tail = 3;  // Pointer to append the next characters
        int num = 1;   // The next digit to append (alternates between 1 and 2)
        int count1 = 1; // Tracks the total count of 1s within the first n elements

        while (tail < n) {
            // Read how many times to repeat the current number
            int repeat = v[head];
            
            for (int i = 0; i < repeat; ++i) {
                v[tail] = num;
                // Only count '1' if it falls within the first n elements
                if (num == 1 && tail < n) {
                    count1++;
                }
                tail++;
            }
            
            head++;
            num = 3 - num; // Flip trick: 3 - 1 = 2, and 3 - 2 = 1
        }

        return count1;
    }
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation.
 * class NestedInteger {
 *   public:
 *     bool isInteger() const;
 *     int getInteger() const;
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> nums;
    int index;

    void flatten(const vector<NestedInteger>& nestedList) {
        for (const auto &x : nestedList) {
            if (x.isInteger()) {
                nums.push_back(x.getInteger());
            } else {
                flatten(x.getList());
            }
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        flatten(nestedList);
    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        return index < nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


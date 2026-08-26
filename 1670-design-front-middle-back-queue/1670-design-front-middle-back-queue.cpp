#include <deque>

class FrontMiddleBackQueue {
private:
    std::deque<int> front_half;
    std::deque<int> back_half;

    // Helper function to restore the size invariant
    void balance() {
        // If front_half gets larger than back_half
        if (front_half.size() > back_half.size()) {
            back_half.push_front(front_half.back());
            front_half.pop_back();
        }
        // If back_half gets more than 1 element larger than front_half
        else if (back_half.size() > front_half.size() + 1) {
            front_half.push_back(back_half.front());
            back_half.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        front_half.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        // If total size is even, front_half and back_half are equal.
        // Pushing to the frontmost middle means adding to the end of front_half.
        if (front_half.size() == back_half.size()) {
            front_half.push_back(val);
        } else {
            // back_half has 1 more element. The true middle falls right before it.
            front_half.push_back(val);
        }
        balance();
    }

    void pushBack(int val) {
        back_half.push_back(val);
        balance();
    }

    int popFront() {
        if (front_half.empty() && back_half.empty()) return -1;
        
        int val;
        if (front_half.empty()) { // Case when there's only 1 element total (stored in back_half)
            val = back_half.front();
            back_half.pop_front();
        } else {
            val = front_half.front();
            front_half.pop_front();
        }
        balance();
        return val;
    }

    int popMiddle() {
        if (front_half.empty() && back_half.empty()) return -1;
        
        int val;
        // If total size is even, choose the frontmost middle (back of front_half)
        if (front_half.size() == back_half.size()) {
            val = front_half.back();
            front_half.pop_back();
        } else { 
            // Total size is odd, back_half contains the single exact middle element
            val = back_half.front();
            back_half.pop_front();
        }
        balance();
        return val;
    }

    int popBack() {
        if (front_half.empty() && back_half.empty()) return -1;
        
        int val = back_half.back();
        back_half.pop_back();
        balance();
        return val;
    }
};

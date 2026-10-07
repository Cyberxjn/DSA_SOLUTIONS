class Solution {
public:
    bool isPalindrome(int x) {
         long long rev = 0;
         int n = x;
         int s;
         int og = x;
    while(n>0){
        s = n % 10;
        rev = rev * 10 +s;
        n /= 10;
    }if (og == rev){
        return true;
        }else{
            return false;
        }
    }
};
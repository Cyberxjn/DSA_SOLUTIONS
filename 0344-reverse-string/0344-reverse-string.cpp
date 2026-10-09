class Solution {
public:
    void reverseString(vector<char>& s) {
       vector<char> rev;
       for(int i=0;i<s.size();i++){
        rev.insert(rev.begin(),s[i]);
       }
       s = rev;
       }
};